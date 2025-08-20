# include "execution.h"

static int pick_up_flags(t_redir redir)
{
    int     flags;

    flags = -1;
    if (redir.type == OP_REDIR_IN)
        flags = O_RDONLY;
    else if (redir.type == OP_REDIR_OUT)
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    else if (redir.type == OP_APPEND)
        flags = O_WRONLY | O_CREAT | O_APPEND;
    return (flags);
}

bool get_redirs(t_tree *branch, t_redir **redirs, int *n_redirs)
{
    *redirs = NULL;
    *n_redirs = 0;
    if (branch->type == COMMAND)
    {
        *redirs = branch->data.cmd.redirs;
        *n_redirs = branch->data.cmd.n_redirs;
    }
    else if (branch->type == SUBSHELL)
    {
        *redirs = branch->data.subshell.redirs;
        *n_redirs = branch->data.subshell.n_redirs;
    }
    return (*n_redirs > 0);
}

bool open_redirections(t_redir *redirs, int n_redirs)
{
    size_t  i;
    int     fd;

    i = -1;
    while (++i < (size_t)n_redirs)
    {
        if (redirs[i].type == OP_HEREDOC)
            continue;
        fd = create_open((char *)redirs[i].file,
                            pick_up_flags(redirs[i]), 0644);
        if (fd < 0)
            return (return_failure((char *)redirs[i].file));
        redirs[i].file = allocate_memory(sizeof(int));
        *(int *)(redirs[i].file) = fd;
    }
    return (true);
}
