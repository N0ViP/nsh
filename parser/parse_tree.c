# include "nsh.h"

void *smalloc(size_t n)
{
    void *pointer;

    pointer = malloc(n);
    if (!pointer)
    {
        perror("malloc");
        exit(EXIT_FAILURE); 
    }
    return pointer;
}

void parse_error(const char *token)
{
    const char *prefix;
    const char *suffix;

    prefix = "syntax error near unexpected token `";
    suffix = "'\n";
    write(2, prefix, ft_strlen(prefix));
    write(2, token, ft_strlen(token));
    write(2, suffix, ft_strlen(suffix));
}

int count_redirs(t_list *tokens)
{
    t_token *tok;
    t_list *cur;
    int count;

    cur = tokens;
    count = 0;
    while (cur)
    {
        tok = (t_token *)cur->content;
        if (tok->type >= OP_APPEND && tok->type <= OP_REDIR_IN)
            count++;
        cur = cur->next;
    }
    return count;
}

static void extract_redirs(t_list **cur, Redir *redirs, int i)
{
    t_token *tok;
    t_token *file_tok;
    t_list  *file_node;

    if (!*cur)
        return;
    tok = (t_token *)(*cur)->content;
    if (tok->type >= OP_APPEND && tok->type <= OP_REDIR_IN)
    {
        file_node = (*cur)->next;
        if (!file_node)
            return ;
        file_tok = (t_token *)file_node->content;
        redirs[i].type = tok->type;
        redirs[i++].file = file_tok->value;
        *cur = file_node->next;
    }
    else
        cur = &((*cur)->next);
    return (extract_redirs(cur, redirs, i));
}

Redir *extract_redirections(t_list **tokens, int n_redirs)
{
    Redir *redirs;

    if (!n_redirs)
        return (NULL);
    redirs = smalloc(sizeof(Redir) * n_redirs);
    extract_redirs(tokens, redirs, 0);
    return (redirs);
}

int count_args(t_list *tokens)
{
    int count;

    count = 0;
    while (tokens) 
    {
        count++;
        tokens = tokens->next;
    }
    return count;
}

char **extract_args(t_list *tokens, int n_arg)
{
    t_token *tok;
    t_list *cur;
    char **args;
    int i;

    i = 0;
    cur = tokens;
    args = smalloc((n_arg + 1) * sizeof(char *));
    while (cur)
    {
        tok = (t_token *)cur->content;
        args[i] = tok->value;
        cur = cur->next;
        i++;
    }
    args[i] = NULL;
    return args;
}

t_tree *new_command_branch(t_list *tokens)
{
    t_tree *node;
    int n_redirs;
    int n_arg;

    node = smalloc(sizeof(t_tree));
    node->type = COMMAND;
    n_redirs = count_redirs(tokens);
    node->data.cmd.n_redirs = n_redirs;
    node->data.cmd.redirs = extract_redirections(&tokens, n_redirs);
    n_arg = count_args(tokens);
    node->data.cmd.n_arg = n_arg;
    node->data.cmd.args = extract_args(tokens, n_arg);
    return (node);
}
static t_tree	*new_operator_branch(t_list *tokens, t_list *split)
{
	t_list			*op_node;
	t_list			*right;
	t_tree			*node;

	op_node = split->next;
	right = op_node->next;
	split->next = NULL;
	node = smalloc(sizeof(t_tree));
	node->type = ((t_token *)op_node->content)->type;
	node->data.branch.left = parse_tokens(tokens);
    if(!(node->data.branch.left))
        return NULL;
	node->data.branch.right = parse_tokens(right);
    if(!(node->data.branch.right))
        return NULL;//free left
	return (node);
}

static t_list	*find_close(t_list *cur)
{
	int		depth;
    t_list	*prev;
	t_token *token;

	depth = 1;
    prev = NULL;
	while (cur && depth)
	{
		token = (t_token *)cur->content;
		if (token->type == OP_OPEN_PARENTHESE)
			depth++;
		else if (token->type == OP_CLOSED_PARENTHESE)
			depth--;
		if (depth == 0)
			return (prev);
        prev = cur;
		cur = cur->next;
	}
	return (NULL);
}
static t_tree	*new_subshell_branch(t_list *tokens)
{
	t_tree	*node;
	t_list  *close;
	t_list	*after;
	t_list	*inside;
	int		n_redirs;

	node = smalloc(sizeof(t_tree));
	inside = tokens->next;
	close = find_close(inside);
	after = close->next->next;
	close->next = NULL;
	node->type = SUBSHELL;
	node->data.subshell.child = parse_tokens(inside);
	n_redirs = count_redirs(after);
	node->data.subshell.n_redirs = n_redirs;
	node->data.subshell.redirs = extract_redirections(&after, n_redirs);
	return (node);
}

static t_list	*find_split_point(t_list *tokens)
{
	t_list	*cur = tokens;
	t_list	*prev = NULL;
	t_list	*split = NULL;
	t_token	*token;
	int		depth = 0;

	while (cur)
	{
		token = (t_token *)cur->content;
		if (token->type == OP_OPEN_PARENTHESE)
			depth++;
		else if (token->type == OP_CLOSED_PARENTHESE)
			depth--;
		else if (!depth && token->type >= OP_OR && token->type <= OP_PIPE)
			if (!split 
                || token->type <= ((t_token *)split->next->content)->type)
				split = prev;
		prev = cur;
		cur = cur->next;
	}
	return (split);
}

t_tree	*parse_tokens(t_list *tokens)
{
	t_list	*split_point;

	split_point = find_split_point(tokens);
	if (split_point)
		return (new_operator_branch(tokens, split_point));
	if (((t_token *)tokens->content)->type == OP_OPEN_PARENTHESE)
		return (new_subshell_branch(tokens));
	return (new_command_branch(tokens));
}



void print_tree(t_tree *root, int indent)
{
    if (!root) return;
    for (int i = 0; i < indent; i++) putchar(' ');

    switch (root->type) {
        case COMMAND:
            printf("CMD: ");
            for (int i = 0; i < root->data.cmd.n_arg; i++)
                printf(" %s", root->data.cmd.args[i]);
            printf("\n");
            for (int i = 0; i < root->data.cmd.n_redirs; i++)
            {
                if(i == 0)
                {
                    for (int j = 0; j < indent; j++) putchar(' ');
                    printf("REDIRS:");
                }
                Redir *r = &root->data.cmd.redirs[i];
                if(!r)
                    return;
                switch (r->type) {
                    case OP_REDIR_IN:     printf(" <%s", r->file); break;
                    case OP_REDIR_OUT:    printf(" >%s", r->file); break;
                    case OP_APPEND:       printf(" >>%s", r->file); break;
                    case OP_HEREDOC:      printf(" >>%s", r->file); break;
                    default: printf("Unknown redir type"); break;
                }
            }
            if(root->data.cmd.n_redirs)
                printf("\n");
            break;

        case OP_PIPE:
            printf("PIPE\n");
            print_tree(root->data.branch.left, indent + 3);
            print_tree(root->data.branch.right, indent + 3);
            break;

        case OP_OR:
            printf("OR (||)\n");
            print_tree(root->data.branch.left, indent + 3);
            print_tree(root->data.branch.right, indent + 3);
            break;

        case OP_AND:
            printf("AND (&&)\n");
            print_tree(root->data.branch.left, indent + 3);
            print_tree(root->data.branch.right, indent + 3);
            break;

        case SUBSHELL:
            printf("SUBSHELL\n");
            print_tree(root->data.subshell.child, indent + 3);
            for (int i = 0; i < root->data.subshell.n_redirs; i++)
            {
                if(i == 0)
                {
                    for (int j = 0; j < indent + 3; j++) putchar(' ');
                    printf("REDIRS:");
                }
                Redir *r = &root->data.subshell.redirs[i];
                if(!r)
                    return;
                switch (r->type) {
                    case OP_REDIR_IN:     printf(" <%s", r->file); break;
                    case OP_REDIR_OUT:    printf(" >%s", r->file); break;
                    case OP_APPEND:       printf(" >>%s", r->file); break;
                    case OP_HEREDOC:      printf(" >>%s", r->file); break;
                    default: printf("Unknown redir type"); break;
                }
            }
            if(root->data.subshell.n_redirs)
                printf("\n");
            break;

        default:
            printf("Unknown node type\n");
            break;
    }
}
