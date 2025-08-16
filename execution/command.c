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
    if (!expand_filenames(branch))
        return (_exit_status(EXTRACT, 0));
    if (!expand_cmd_args(branch))
        return (_exit_status(EXTRACT, 0));
    if (built_ins_check(branch))
        return (_exit_status(EXTRACT, 0));
    else if (mode == DEFAULT_MODE)
        return (fork_before(execute, branch));
    execute(branch);
    return (EXIT_FAILURE);
}
