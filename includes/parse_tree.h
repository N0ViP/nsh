#ifndef PARSE_TREE_H
# define PARSE_TREE_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;
typedef struct s_token		t_token;

typedef struct {
    enum e_operator type;
    char *file;
} Redir;

typedef struct {
    char *args;
    int  sp_bf;
} Args;

typedef struct {
    const char  *string;
    int         start, end;
} t_slice;

typedef struct {
    Args  *args;
    int   n_arg;
    Redir *redirs;
    int    n_redirs;
} t_cmd;

typedef struct {
    struct TreeNode *left;
    struct TreeNode *right;
} t_pipe;

typedef struct TreeNode {
    enum e_operator type;
    union {
        t_cmd  cmd;
        t_pipe pipe;
    } data;
} TreeNode;

TreeNode    *parse_tokens(t_list_info *tokens);
void        print_tree(TreeNode *root, int indent);

#endif