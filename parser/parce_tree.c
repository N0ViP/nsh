# include "nsh.h"

// void parse_error(const char *token) {
//     const char *prefix = "parse error near `";
//     const char *suffix = "'\n";

//     write(2, prefix, strlen(prefix));
//     write(2, token, strlen(token));
//     write(2, suffix, strlen(suffix));
// }

// int count_redirs(list *tokens)
// {
//     int count = 0;
//     while (tokens) {
//         if (tokens->is_op >= NODE_REDIR_IN)
//             count++;
//         tokens = tokens->next;
//     }
//     return count;
// }

// void free_two_nodes(list *node)
// {
//     if (!node) return;
//     list *next_node = node->next;
//     free(node->str);
//     free(node);
//     if (next_node)
//         free(next_node);
// }


// Redir *extract_redirections(list **tokens, int n_redirs)
// {
//     Redir *redirs = smalloc(n_redirs * sizeof(Redir));
//     list *cur = *tokens;
//     list *prev = NULL;
//     int r = 0;
//     while (cur) {
//         if (cur->is_op >= NODE_REDIR_IN)
//         {
//             if (!cur->next)
//                 return (parse_error("\\n"), NULL);
//             redirs[r].type = cur->is_op;
//             redirs[r++].file = cur->next->str;
//             list *next_next = cur->next->next;
//             free_two_nodes(cur);
//             if (prev)
//                 prev->next = next_next;
//             else
//                 *tokens = next_next;
//             cur = next_next;
//         }
//         else
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//     }
//     return redirs;
// }


// int count_args(list *tokens)
// {
//     int count = 0;
//     while (tokens) 
//     {
//         count++;
//         tokens = tokens->next;
//     }
//     return count;
// }

// Args *extract_args(list *tokens, int n_arg)
// {
//     list *cur = tokens;
//     list *next = NULL;
//     Args *args = smalloc((n_arg + 1) * sizeof(Args));
//     cur = tokens;
//     int i = 0;
//     while (cur) 
//     {
//         args[i].sp_bf = cur->is_sp;
//         args[i++].args = cur->str;
//         next = cur->next;
//         free(cur);
//         cur = next;
//     }
//     args[0].sp_bf = 0;
//     return args;
// }



// TreeNode *new_command_node(list *tokens)
// {
//     TreeNode *node = smalloc(sizeof(TreeNode));
//     node->type = NODE_CMD;

//     int n_redirs = count_redirs(tokens);
//     node->data.cmd.redirs = extract_redirections(&tokens, n_redirs);
//     node->data.cmd.n_redirs = n_redirs;

//     int n_arg = count_args(tokens);
//     node->data.cmd.args = extract_args(tokens, n_arg);
//     node->data.cmd.n_arg = n_arg;

//     return node;
// }




// static TreeNode *new_pipe_node(list *tokens, list *after_pipe)
// {
//     TreeNode *n = smalloc(sizeof(TreeNode));

//     n->type = NODE_PIPE;
//     n->data.pipe.left  = parse_tokens(tokens);
//     n->data.pipe.right = new_command_node(after_pipe);
//     return n;
// }

TreeNode *parse_tokens(s_list_info *tokens)
{

    return NULL;
    if (!tokens) return NULL;

    // t_list *cur = tokens->list, *last_pipe = NULL, *prev = NULL, *prev_to_pipe = NULL;
    // while (cur) 
    // {
    //     if (cur->content->type == OP_PIPE) 
    //     {
    //         last_pipe    = cur;
    //         prev_to_pipe = prev;
    //     }
    //     prev = cur;
    //     cur  = cur->next;
    // }

    // if (last_pipe) 
    // {
    //     t_list *after_pipe = last_pipe->next;
    //     if (prev_to_pipe) prev_to_pipe->next = NULL;
    //     else              tokens = NULL;

    //     free(last_pipe->str);
    //     free(last_pipe);

    //     return new_pipe_node(tokens, after_pipe);
    // }

    // return new_command_node(tokens);
}

// void free_tree(TreeNode *root)
// {
//     if (!root)
//         return;

//     if (root->type == NODE_CMD) 
//     {
//         for (int i = 0; i < root->data.cmd.n_redirs; i++) 
//         {
//             free(root->data.cmd.redirs[i].file);
//         }
//         free(root->data.cmd.redirs);

//         for (int i = 0; i < root->data.cmd.n_arg; i++) 
//         {
//             free(root->data.cmd.args[i].args);
//         }
//         free(root->data.cmd.args);
//     }
//     else if (root->type == NODE_PIPE) 
//     {
//         free_tree(root->data.pipe.left);
//         free_tree(root->data.pipe.right);
//     }

//     free(root);
// }

void print_tree(TreeNode *root, int indent)
{
    // if (!root) return;
    // for (int i = 0; i < indent; i++) putchar(' ');

    // if (root->type == NODE_CMD) {
    //     printf("CMD: ");
    //     for (int i = 0; i < root->data.cmd.n_arg; i++)
    //         if(root->data.cmd.args[i].sp_bf)
    //             printf(" %s", root->data.cmd.args[i].args);
    //         else
    //             printf("%s", root->data.cmd.args[i].args);
    //     printf("\n");

    //     for (int i = 0; i < root->data.cmd.n_redirs; i++) {
    //         Redir *r = &root->data.cmd.redirs[i];
    //         if(!r)
    //             return;
    //         for (int j = 0; j < indent+3; j++) putchar(' ');
    //         switch (r->type) {
    //             case NODE_REDIR_IN:     printf("<  %s\n", r->file); break;
    //             case NODE_REDIR_OUT:    printf(">  %s\n", r->file); break;
    //             case NODE_REDIR_APPEND: printf(">> %s\n", r->file); break;
    //             case NODE_REDIR_HEREDOC: printf(">> %s\n", r->file); break;
    //             default: break;
    //         }
    //     }
    // }
    // else {
    //     printf("PIPE\n");
    //     print_tree(root->data.pipe.left,  indent+3);
    //     print_tree(root->data.pipe.right, indent+3);
    // }
}
