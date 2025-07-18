#ifndef EXECUTION_H
# define EXECUTION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"
# include "errno.h"
# include <sys/stat.h>
# include <sys/wait.h>

typedef enum
{
    VALID_PATH,
    NOT_FOUND_ERROR,
    NO_FILE_ERROR,
    IS_DIR_ERROR,
    PERMISSION_ERROR,
    STAT_ERROR
}   t_state;


int execute_tree(t_tree *root, char **envp);

#endif