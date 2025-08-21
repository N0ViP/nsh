# include "execution.h"

int child_status(int status)
{
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    if (WIFSIGNALED(status))
        return (128 + WTERMSIG(status));
    return (EXIT_FAILURE);
}

int fork_before(void (*keep_exec)(t_tree *), t_tree *branch)
{
    int status;
    pid_t pid;

    status = 0;
    pid = fork();
    if (pid < 0)
        exit_failure("fork");
    if (pid == 0)
    {
        child_mode_signals();
        iam_a_child(UPDATE);
        keep_exec(branch);
    }
    waitpid(pid, &status, 0);
    return (child_status(status));
}

