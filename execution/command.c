# include "execution.h"

static void execute(t_tree *branch)
{
    char   *path;
    char   **env;
    char   **argv;
    
    redirection_setup(branch);
    argv = branch->data.cmd.args;
    path = path_resolution(argv[0]);
    env = lst_to_arr(*env_list());
    execve(path, argv, env);
    exit_failure("execve");
}

int execute_command(t_tree *branch, t_mode mode)
{
    int exit_status;

    exit_status = check_for_heredoc(branch);
    if (!branch->data.cmd.n_arg || exit_status == 130)
        return (exit_status);
    expand_cmd_args(&branch->data.cmd);
    if (!branch->data.cmd.args || !branch->data.cmd.args[0])
        return (exit_status);
    if (built_ins_check(branch, &exit_status))
        return (exit_status);
    else if (mode == DEFAULT_MODE)
        return (fork_before(execute, branch));
    execute(branch);
    return (exit_status);
}
