# include "execution.h"

pid_t fork_left_pipe(int pipefd[2], t_tree *branch)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		exit_failure("fork");
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exit_shell(execution_mode(branch->data.branch.left, NO_FORK_MODE));
	}
	return (pid);
}

pid_t fork_right_pipe(int pipefd[2], t_tree *branch)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
		exit_failure("fork");
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		exit_shell(execution_mode(branch->data.branch.right, NO_FORK_MODE));
	}
	return (pid);
}
