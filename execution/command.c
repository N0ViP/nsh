# include "execution.h"

static void execute(t_tree *branch)
{
    char   *path;
    char   **env;
    char   **argv;
    
    check_redirection(branch);
    argv = expand_cmd_args(&branch->data.cmd);
    path = path_resolution(argv[0]);
    env = lst_to_arr(*env_list());
    execve(path, argv, env);
    exit_failure("execve");
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
