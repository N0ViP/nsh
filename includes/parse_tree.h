#ifndef PARSE_TREE_H
# define PARSE_TREE_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;
typedef struct s_token		t_token;

enum e_operator { //op??
	WORD,
	OP_OR,
	OP_AND,
	OP_PIPE,
	OP_APPEND,
	OP_HEREDOC,
	OP_REDIR_OUT,
	OP_REDIR_IN,
	OP_OPEN_PARENTHESE,
	OP_CLOSED_PARENTHESE,
	SUBSHELL,
    COMMAND
};

typedef struct {
    enum e_operator type;
    char *file;
} Redir;

// typedef struct {
//     const char  *string;
//     int         start, end;
// } t_slice;

typedef struct {
    char    **args;
    int     n_arg;
    Redir   *redirs;
    int     n_redirs;
} t_cmd;

typedef struct s_branch {
    struct s_tree *left;
    struct s_tree *right;
} t_branch;

typedef struct s_tree {
    enum e_operator type;
    union {
        t_cmd  cmd;
        t_branch branch;
        struct s_tree *subshell;
    } data;
} t_tree;





t_tree    *parse_tokens(t_list *tokens);
void        print_tree(t_tree *root, int indent);

#endif