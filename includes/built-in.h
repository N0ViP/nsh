#ifndef	BUILT_IN_H
# define BUILT_IN_H

#include "nsh.h"
#include "execution.h"
#include "utils.h"
#include "stdfcts.h"
// #include <linux/limits.h>


int		built_in_env(void);
int 	built_in_echo(char **arr);
int		built_in_unset(char **args);
int     built_in_export(char **args);
int	    built_in_exit(char **argv, int n_arg);


#endif
