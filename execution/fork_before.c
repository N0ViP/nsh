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
        keep_exec(branch);
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status))
        return (EXIT_FAILURE);
    return (WEXITSTATUS(status));
}
