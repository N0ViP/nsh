# include "execution.h"

static pid_t fork_left_pipe(int pipefd[2], t_tree *branch, char **envp)
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
		exit(execution_mode(branch->data.branch.left, envp, NO_FORK_MODE));
	}
	return (pid);
}

static pid_t fork_right_pipe(int pipefd[2], t_tree *branch, char **envp)
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
		exit(execution_mode(branch->data.branch.right, envp, NO_FORK_MODE));
	}
	return (pid);
}

static int fork_both_sides(int pipefd[2], t_tree *branch, char **envp)
{
	pid_t left, right;
	int   status;

	left  = fork_left_pipe(pipefd, branch, envp);
	right = fork_right_pipe(pipefd, branch, envp);

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(left,  NULL, 0);
	waitpid(right, &status, 0);
	if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

static int fork_right_only(int pipefd[2], t_tree *branch, char **envp)
{
	pid_t right;
	int   status;

	right = fork_right_pipe(pipefd, branch, envp);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execution_mode(branch->data.branch.left, envp, NO_FORK_MODE);

	waitpid(right, &status, 0);
	if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

int execute_pipeline(t_tree *branch, char **envp, t_mode mode)
{
	int   pipefd[2];

	if (pipe(pipefd) < 0)
		exit_failure("pipe");

    if (mode == DEFAULT_MODE)
        return (fork_both_sides(pipefd, branch, envp));
    return (fork_right_only(pipefd, branch, envp));
}
