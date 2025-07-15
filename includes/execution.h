#ifndef EXECUTION_H
# define EXECUTION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"

int execute_tree(t_tree *root, char **envp);

#endif