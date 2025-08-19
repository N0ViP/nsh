# include "execution.h"

static void redir_then_recurse(t_tree *branch)
{
    t_tree *child;
    int     status;

    if (!expand_filenames(branch))
        exit_shell(EXIT_FAILURE);
    redirection_setup(branch);
    child = branch->data.subshell.child;
    status = execution_mode(child, NO_FORK_MODE);
    exit_shell(status);
}

int execute_subshell(t_tree *branch, t_mode mode)
{
    if (mode == DEFAULT_MODE)
        return (fork_before(redir_then_recurse, branch));
    return (redir_then_recurse(branch), 1);
}