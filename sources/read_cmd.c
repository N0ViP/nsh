/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:33:28 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:33:29 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

bool	read_command(char **cmd)
{
	read_mode_signals();
	*cmd = readline("nsh$ ");
	parent_mode_signals();
	if (!*cmd)
	{
		write(STDERR_FILENO, "exit\n", 5);
		exit_shell(_exit_status(EXTRACT, 0));
	}
	else if (!**cmd)
	{
		free(*cmd);
		return (false);
	}
	add_history(*cmd);
	return (true);
}
