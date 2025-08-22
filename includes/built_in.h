/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:26:26 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:45:34 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "nsh.h"

bool	go_home(void);
bool	update_pwd(void);
bool	go_old_pwd(void);
char	*update_cwd(void);
char	**shell_cwd(void);
void	update_oldpwd(void);
bool	iam_a_child(int flag);
bool	go_to_path(char *path);
int		built_in_cd(t_cmd *cmd_args);
int		built_in_env(t_cmd *cmd_args);
int		built_in_pwd(t_cmd *cmd_args);
int		built_in_exit(t_cmd *cmd_args);
int		built_in_echo(t_cmd *cmd_args);
int		built_in_unset(t_cmd *cmd_args);
int		built_in_export(t_cmd *cmd_args);
void	print_cd_error(char *path, char *error);
void	print_exit_error(char *error, char *arg);
bool	arg_to_exit_code(char *str, long long *exit_code);
bool	run_buit_in(int (*buit_in)(t_cmd *), t_tree *branch);

#endif
