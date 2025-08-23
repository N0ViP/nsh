/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_left_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:41 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 06:38:58 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

pid_t	fork_left_pipe(int pipefd[2], t_tree *branch)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_failure("fork");
	if (pid == 0)
	{
		child_mode_signals();
		iam_a_child(UPDATE);
		close_and_remove(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close_and_remove(pipefd[1]);
		exit_shell(execution_mode(branch->u_data.branch.left, FORKED_MODE));
	}
	return (pid);
}

pid_t	fork_right_pipe(int pipefd[2], t_tree *branch)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_failure("fork");
	if (pid == 0)
	{
		child_mode_signals();
		iam_a_child(UPDATE);
		close_and_remove(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close_and_remove(pipefd[0]);
		exit_shell(execution_mode(branch->u_data.branch.right, FORKED_MODE));
	}
	return (pid);
}
