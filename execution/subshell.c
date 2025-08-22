/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:46 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:55:35 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	redir_then_recurse(t_tree *branch)
{
	t_tree	*child;
	int		status;

	if (!expand_filenames(branch))
		exit_shell(_exit_status(EXTRACT, 0));
	dup_redirections(branch);
	child = branch->u_data.subshell.child;
	status = execution_mode(child, NO_FORK_MODE);
	exit_shell(status);
}

int	execute_subshell(t_tree *branch, t_mode mode)
{
	if (mode == DEFAULT_MODE)
		return (fork_before(redir_then_recurse, branch));
	return (redir_then_recurse(branch), 1);
}
