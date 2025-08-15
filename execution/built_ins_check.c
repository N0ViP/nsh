# include "execution.h"

bool built_ins_check(t_tree *branch, int *exit_status)
{
    char   **argv;

    argv = branch->data.cmd.args;
    if (!ft_strcmp(argv[0], "export"))
        return (*exit_status = built_in_export(argv), true);
    else if (!ft_strcmp(argv[0], "unset"))
        return (*exit_status = built_in_unset(argv), true);
    else if (!ft_strcmp(argv[0], "echo"))
        return (*exit_status = built_in_echo(argv), true);
    else if (!ft_strcmp(argv[0], "env"))
        return (*exit_status = built_in_env(), true);
    return (false);
}
