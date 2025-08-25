/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:07 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 06:19:11 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

bool	built_ins_check(t_tree *branch)
{
	char	**argv;

	argv = branch->u_data.cmd.args;
	if (!ft_strcmp(argv[0], "cd"))
		return (run_buit_in(built_in_cd, branch));
	else if (!ft_strcmp(argv[0], "pwd"))
		return (run_buit_in(built_in_pwd, branch));
	else if (!ft_strcmp(argv[0], "env"))
		return (run_buit_in(built_in_env, branch));
	else if (!ft_strcmp(argv[0], "echo"))
		return (run_buit_in(built_in_echo, branch));
	else if (!ft_strcmp(argv[0], "exit"))
		return (run_buit_in(built_in_exit, branch));
	else if (!ft_strcmp(argv[0], "unset"))
		return (run_buit_in(built_in_unset, branch));
	else if (!ft_strcmp(argv[0], "export"))
		return (run_buit_in(built_in_export, branch));
	return (false);
}
