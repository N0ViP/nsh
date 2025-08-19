# include "execution.h"

static int fork_both_sides(int pipefd[2], t_tree *branch)
{
	int   status;
	pid_t right;
	pid_t left;

	left  = fork_left_pipe(pipefd, branch);
	right = fork_right_pipe(pipefd, branch);

	close_and_remove(pipefd[0]);
	close_and_remove(pipefd[1]);
	waitpid(left,  NULL, 0);
	waitpid(right, &status, 0);
	if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

static int fork_right_only(int pipefd[2], t_tree *branch)
{
	pid_t right;
	int   status;

	right = fork_right_pipe(pipefd, branch);
	dup2(pipefd[1], STDOUT_FILENO);
	close_and_remove(pipefd[0]);
	close_and_remove(pipefd[1]);
	execution_mode(branch->data.branch.left, NO_FORK_MODE);

	waitpid(right, &status, 0);
	if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

int execute_pipeline(t_tree *branch, t_mode mode)
{
	int   pipefd[2];

	if (!create_pipe(pipefd))
		exit_failure("pipe");
    if (mode == DEFAULT_MODE)
        return (fork_both_sides(pipefd, branch));
    return (fork_right_only(pipefd, branch));
}
