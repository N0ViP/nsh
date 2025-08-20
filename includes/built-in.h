#ifndef	BUILT_IN_H
# define BUILT_IN_H

#include "nsh.h"

bool    go_home(void);
bool    update_pwd(void);
bool    go_old_pwd(void);
char    *update_cwd(void);
char    **shell_cwd(void);
void    update_oldpwd(void);
bool    go_to_path(char *path);
int     built_in_cd(t_cmd *cmd_args);
int		built_in_env(t_cmd *cmd_args);
int	    built_in_pwd(t_cmd *cmd_args);
int	    built_in_exit(t_cmd *cmd_args);
int 	built_in_echo(t_cmd *cmd_args);
int		built_in_unset(t_cmd *cmd_args);
int     built_in_export(t_cmd *cmd_args);
void    print_cd_error(char *path, char *error);
void    print_exit_error(char *error, char *arg);
bool    arg_to_exit_code(char *str, long long *exit_code);
bool    run_buit_in(int (*buit_in)(t_cmd *), t_tree *branch);


#endif
