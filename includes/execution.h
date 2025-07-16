#ifndef EXECUTION_H
# define EXECUTION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"
# include <sys/stat.h>

typedef enum e_err
{
    ERR_CMD_NOT_FOUND,
    ERR_NO_FILE,
    ERR_DIR,
    ERR_PERM
}   t_err;


int execute_tree(t_tree *root, char **envp);

#endif