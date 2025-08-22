/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_curr_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:56 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:20:57 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*check_and_curr_dir(char *cmd)
{
	char	*cmd_path;
	t_state	state;

	cmd_path = join_two_strings(".", cmd, "/");
	state = path_validity(cmd_path);
	if (state == VALID_PATH)
	{
		return (cmd_path);
	}
	else
	{
		cmd = ft_strdup(cmd);
	}
	return (report_error(cmd, state), NULL);
}
