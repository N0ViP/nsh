# include "execution.h"

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
        child_signals();
        keep_exec(branch);
    }
    waiting_signals();
    waitpid(pid, &status, 0);
    shell_signals();
    // if (WIFSIGNALED(status))
    //     if (WTERMSIG(status) == SIGINT ||
    //         WTERMSIG(status) == SIGQUIT)
    //         write(STDOUT_FILENO, "\n", 1);//set the g better
    if (!WIFEXITED(status))
        return (EXIT_FAILURE);
    return (WEXITSTATUS(status));
}

