# include "execution.h"

static void execute(t_tree *branch)
{
    char    *path;
    char   **argv;
    char   **envi;
    
    check_redirection(branch);
    argv = expand_cmd_args(&branch->data.cmd);
    path = path_resolution(argv[0]);
    envi = lst_to_arr(ft_getenv(GET_ENV, NULL));
    execve(path, argv, envi);
    exit_failure("execve");
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
        keep_exec(branch);
    waitpid(pid, &status, 0);
    if (!WIFEXITED(status))
        return (EXIT_FAILURE);
    return (WEXITSTATUS(status));
}

int execute_command(t_tree *branch, t_mode mode)
{
    int exit_status;

    exit_status = 1;
    if (built_ins_check(branch, &exit_status))
        return (exit_status);
    else if (mode == DEFAULT_MODE)
        return (fork_before(execute, branch));
    execute(branch);
    return (exit_status);
}
