/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_built_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:42 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:54:40 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static bool	save_stdio(int saved[3])
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		saved[i] = duplicate_fd(i);
		if (saved[i] < 0)
			return (_exit_status(UPDATE, 1), false);
		i++;
	}
	return (true);
}

static void	restore_stdio(int saved[3])
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		dup2(saved[i], i);
		close_and_remove(saved[i]);
		i++;
	}
}

bool	run_buit_in(int (*buit_in)(t_cmd *), t_tree *branch)
{
	t_cmd	*cmd_args;
	int		saved[3];

	cmd_args = &branch->u_data.cmd;
	if (!save_stdio(saved))
		return (true);
	dup_redirections(branch);
	_exit_status(UPDATE, buit_in(cmd_args));
	restore_stdio(saved);
	return (true);
}
