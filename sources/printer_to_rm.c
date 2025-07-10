# include "nsh.h"

const char *operator_type_name(enum e_operator type) {
    switch (type) {
        case WORD:              return "WORD";
        case OP_OR:             return "OP_OR";
        case OP_AND:            return "OP_AND";
        case OP_APPEND:         return "OP_APPEND";
        case OP_HEREDOC:        return "OP_HEREDOC";
        case OP_REDIR_OUT:      return "OP_REDIR_OUT";
        case OP_REDIR_IN:       return "OP_REDIR_IN";
        case OP_OPEN_PARENTHESE:return "OP_OPEN_PARENTHESE";
        case OP_CLOSED_PARENTHESE:return "OP_CLOSED_PARENTHESE";
        case OP_PIPE:           return "OP_PIPE";
        case SUBSHELL:          return "SUBSHELL";
        case COMMAND:           return "COMMAND";
        default:                return "UNKNOWN";
    }
}

void print_tokens(t_list *list)
{
	if (!list) return;
    while (list)
    {
        t_token *token = (t_token *)list->content;
        printf("TOKEN___%s_______%s\n", token->value, operator_type_name(token->type));
        list = list->next;
    }
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
