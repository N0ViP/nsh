/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:05 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 04:31:02 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execution_mode(t_tree *root, t_mode mode)
{
	if (root->type == COMMAND)
		return (_exit_status(UPDATE, execute_command(root, mode)));
	else if (root->type == SUBSHELL)
		return (_exit_status(UPDATE, execute_subshell(root, mode)));
	else if (root->type == OP_PIPE)
		return (_exit_status(UPDATE, execute_pipeline(root, mode)));
	else if (root->type == OP_OR || root->type == OP_AND)
		return (_exit_status(UPDATE, execute_or_and(root)));
	return (EXIT_FAILURE);
}

void	execute_tree(t_tree *root)
{
	int	exit_status;

	if (!look_for_heredocs(root))
		return ;
	exit_status = execution_mode(root, DEFAULT_MODE);
	_exit_status(UPDATE, exit_status);
}
