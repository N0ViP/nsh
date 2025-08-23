/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:32 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 07:10:37 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void close_stdio(void)
{
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
}

static int	fork_both_sides(int pipefd[2], t_tree *branch)
{
	int		status;
	pid_t	right;
	pid_t	left;

	left = fork_left_pipe(pipefd, branch);
	right = fork_right_pipe(pipefd, branch);
	close_and_remove(pipefd[0]);
	close_and_remove(pipefd[1]);
	waitpid(left, NULL, 0);
	waitpid(right, &status, 0);
	return (child_status(status));
}

static int	close_after_fork(int pipefd[2], t_tree *branch)
{
	int		status;
	pid_t	right;
	pid_t	left;

	left = fork_left_pipe(pipefd, branch);
	right = fork_right_pipe(pipefd, branch);
	close_and_remove(pipefd[0]);
	close_and_remove(pipefd[1]);
	close_stdio();
	waitpid(left, NULL, 0);
	waitpid(right, &status, 0);
	return (child_status(status));
}

int	execute_pipeline(t_tree *branch, t_mode mode)
{
	int	pipefd[2];

	if (!create_pipe(pipefd))
		exit_failure("pipe");
	if (mode == DEFAULT_MODE)
		return (fork_both_sides(pipefd, branch));
	return (close_after_fork(pipefd, branch));
}
