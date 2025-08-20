# include "execution.h"

static bool save_stdio(int saved[3])
{
    int i;

    i = 0;
    while (i <= 2)
    {
        saved[i] = duplicate_fd(i);
        if (saved[i] < 0)
            return (_exit_status(UPDATE, 1), false);
        i++;
    }
    return (true);
}

static void restore_stdio(int saved[3])
{
    int i;

    i = 0;
    while (i <= 2)
    {
        dup2(saved[i], i);
        close_and_remove(saved[i]);
        i++;
    }
}
// export A=B C=D && env | grep -E 'A=|C='
bool run_buit_in(int (*buit_in)(t_cmd *), t_tree *branch)
{
    t_cmd   *cmd_args;
    int     saved[3];

    cmd_args = &branch->data.cmd;
    if (!save_stdio(saved))
        return (true);
    if (!redirection_setup(branch))
        return (restore_stdio(saved), true);
    _exit_status(UPDATE, buit_in(cmd_args));
    restore_stdio(saved);
    return(true);
}
