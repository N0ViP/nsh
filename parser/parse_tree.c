# include "nsh.h"

void *smalloc(size_t n)
{
    void *p = malloc(n);
    if (!p) { perror("malloc"); exit(EXIT_FAILURE); }
    return p;
}

void parse_error(const char *token)
{
    const char *prefix = "syntax error near unexpected token `";
    const char *suffix = "'\n";

    write(2, prefix, strlen(prefix));
    write(2, token, strlen(token));
    write(2, suffix, strlen(suffix));
}

int count_redirs(t_list *tokens)
{
    int count = 0;
    t_list *cur = tokens;
    while (cur)
    {
        t_token *tok = (t_token *)cur->content;
        if (tok->type >= OP_APPEND && tok->type <= OP_REDIR_IN)
            count++;
        cur = cur->next;
    }
    return count;
}

Redir *extract_redirections(t_list **tokens, int n_redirs)
{
    if(!n_redirs)
        return NULL;
    Redir *redirs = smalloc(n_redirs * sizeof(Redir));
    t_list *cur = *tokens;
    t_list *prev = NULL;
    int r = 0;
    while (cur)
    {
        t_token *tok = (t_token *)cur->content;
        if (tok->type >= OP_APPEND && tok->type <= OP_REDIR_IN)
        {
            if (!cur->next)
                return (parse_error("\\n"), NULL);

            t_list *file_node = cur->next;
            t_token *file_tok = (t_token *)file_node->content;

            redirs[r].type = tok->type;
            redirs[r++].file = file_tok->value;

            t_list *next_next = file_node->next;

            if (prev)
                prev->next = next_next;
            else
                *tokens = next_next;
            cur = next_next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return redirs;
}

int count_args(t_list *tokens)
{
    int count = 0;
    while (tokens) 
    {
        count++;
        tokens = tokens->next;
    }
    return count;
}

char **extract_args(t_list *tokens, int n_arg)
{
    char **args;
    t_list *cur;
    t_token *tok;
    int i;

    args = smalloc((n_arg + 1) * sizeof(char *));
    cur = tokens;
    i = 0;
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
    t_tree *node = smalloc(sizeof(t_tree));
    node->type = COMMAND;

    int n_redirs = count_redirs(tokens);
    node->data.cmd.redirs = extract_redirections(&tokens, n_redirs);
    node->data.cmd.n_redirs = n_redirs;

    int n_arg = count_args(tokens);
    node->data.cmd.args = extract_args(tokens, n_arg);
    node->data.cmd.n_arg = n_arg;

    return node;
}

static t_tree *new_operator_branch(t_list *tokens, t_list *split_point)
{
    t_list *op_node = split_point->next;
    t_token *op_token = (t_token *)op_node->content;
    enum e_operator type = op_token->type;

    t_list *right_tokens = op_node->next;
    split_point->next = NULL;

    t_tree *node = smalloc(sizeof(t_tree));
    node->type = type;
    node->data.branch.left = parse_tokens(tokens);
    if(!(node->data.branch.left))
        return NULL;
    node->data.branch.right = parse_tokens(right_tokens);
    if(!(node->data.branch.right))
        return NULL;//free left
    return node;
}

static t_list *copy_token_segment(t_list *start, t_list *end)
{
    t_list *head = NULL;
    t_list *tail = NULL;
    t_list *cur = start;

    while (end && cur != end)
    {
        t_list *new_node = smalloc(sizeof(t_list));
        new_node->content = cur->content;
        new_node->next = NULL;
        
        if (!head) head = new_node;
        else tail->next = new_node;
        
        tail = new_node;
        cur = cur->next;
    }    
    while (!end && cur)
    {
        t_list *new_node = smalloc(sizeof(t_list));
        new_node->content = cur->content;
        new_node->next = NULL;
        
        if (!head) head = new_node;
        else tail->next = new_node;
        
        tail = new_node;
        cur = cur->next;
    }
    return head;
}

static t_tree *new_subshell_branch(t_list *subshell)
{
    int depth = 1;
    t_list *end = subshell->next;
    while (end && depth)
    {
        t_token *tk = end->content;
        if (tk->type == OP_OPEN_PARENTHESE)   depth++;
        else if (tk->type == OP_CLOSED_PARENTHESE) depth--;
        if (depth == 0) break;
        end = end->next;
    }

    t_list *inside = copy_token_segment(subshell->next, end);
    end = copy_token_segment(end->next, NULL);
    t_tree *node = smalloc(sizeof *node);
    node->type = SUBSHELL;
    node->data.subshell.child = parse_tokens(inside);

    int n_redirs = count_redirs(end);
    node->data.subshell.redirs = extract_redirections(&end, n_redirs);
    node->data.subshell.n_redirs = n_redirs;
    
    if(!(node->data.subshell.child))
        return NULL;

    return node;
}

t_tree *parse_tokens(t_list *tokens)
{
    if (!tokens || !parse_check(tokens))//no need to be in recursion
		return (NULL);
  
    t_list *cur = tokens, *prev = NULL;
    t_list *last_or = NULL, *last_and = NULL, *last_pipe = NULL;
    int depth = 0;

    while (cur)
    {
        t_token *tk = cur->content;
        if (tk->type == OP_OPEN_PARENTHESE)   depth++;
        else if (tk->type == OP_CLOSED_PARENTHESE) depth--;
        else if (depth == 0)
        {
            if (tk->type == OP_OR)   last_or  = prev;
            if (tk->type == OP_AND)  last_and = prev;
            if (tk->type == OP_PIPE) last_pipe= prev;
        }
        prev = cur;
        cur  = cur->next;
    }

    if(last_or) 
        return new_operator_branch(tokens, last_or);
    else if(last_and) 
        return new_operator_branch(tokens, last_and);
    else if(last_pipe) 
        return new_operator_branch(tokens, last_pipe);
    else if (((t_token*)tokens->content)->type == OP_OPEN_PARENTHESE)
        return new_subshell_branch(tokens);

    return new_command_branch(tokens);
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
            for (int i = 0; i < root->data.cmd.n_redirs; i++) {
                Redir *r = &root->data.cmd.redirs[i];
                if(!r)
                    return;
                for (int j = 0; j < indent+3; j++) putchar(' ');
                switch (r->type) {
                    case OP_REDIR_IN:     printf("<  %s\n", r->file); break;
                    case OP_REDIR_OUT:    printf(">  %s\n", r->file); break;
                    case OP_APPEND: printf(">> %s\n", r->file); break;
                    case OP_HEREDOC: printf(">> %s\n", r->file); break;
                    default: break;
                }
            }
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
            for (int i = 0; i < indent; i++) putchar(' ');
            for (int i = 0; i < root->data.subshell.n_redirs; i++) {
                Redir *r = &root->data.subshell.redirs[i];
                if(!r)
                    return;
                for (int j = 0; j < indent + 3; j++) putchar(' ');
                switch (r->type) {
                    case OP_REDIR_IN:     printf("<  %s\n", r->file); break;
                    case OP_REDIR_OUT:    printf(">  %s\n", r->file); break;
                    case OP_APPEND: printf(">> %s\n", r->file); break;
                    case OP_HEREDOC: printf(">> %s\n", r->file); break;
                    default: break;
                }
            }
            break;

        default:
            printf("Unknown node type\n");
            break;
    }
}
