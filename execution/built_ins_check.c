# include "execution.h"

bool built_ins_check(t_tree *branch)
{
    char   **argv;
    int    n_arg;

    argv = branch->data.cmd.args;
    n_arg = branch->data.cmd.n_arg;
    if (!ft_strcmp(argv[0], "export"))
        return (_exit_status(UPDATE, built_in_export(argv)), true);
    else if (!ft_strcmp(argv[0], "unset"))
        return (_exit_status(UPDATE, built_in_unset(argv)), true);
    else if (!ft_strcmp(argv[0], "echo"))
        return (_exit_status(UPDATE, built_in_echo(argv)), true);
    else if (!ft_strcmp(argv[0], "env"))
        return (_exit_status(UPDATE, built_in_env()), true);
    else if (!ft_strcmp(argv[0], "exit"))
        return (_exit_status(UPDATE, built_in_exit(argv, n_arg)), true);
    return (false);
}
