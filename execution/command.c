# include "execution.h"

static void execute(t_tree *branch, char **envp)
{
    char    *path;
    char   **argv;
    
    check_redirection(branch);
    argv = expand_cmd_args(&branch->data.cmd);
    path = resolve_path(argv[0]);
    execve(path, argv, envp);
    exit_failure("execve");
}

int fork_before(void (*keep_exec)(t_tree *, char **), t_tree *branch, char **envp)
{
    int status;
    pid_t pid;

    status = 0;
    pid = fork();
    if (pid < 0)
        exit_failure("fork");
    if (pid == 0)
        keep_exec(branch, envp);
    waitpid(pid, &status, 0);
    return (WEXITSTATUS(status));
}

int execute_command(t_tree *branch, char **envp, t_mode mode)
{
    if (mode == DEFAULT_MODE)
        return (fork_before(execute, branch, envp));
    execute(branch, envp);
    return (1);
}
