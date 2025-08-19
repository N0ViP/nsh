#ifndef	BUILT_IN_H
# define BUILT_IN_H

#include "nsh.h"

char    *update_cwd(void);
char    **shell_cwd(void);
int		built_in_env(void);
int	    built_in_pwd(void);
int     built_in_cd(char **args);
int 	built_in_echo(char **arr);
int		built_in_unset(char **args);
int     built_in_export(char **args);
int	    built_in_exit(char **argv, int n_arg);


#endif
