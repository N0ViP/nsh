# include "execution.h"

static bool check_redirection(t_redir redir)
{
    if (redir.type == OP_REDIR_IN)
    {
        if (open_redirect((char *)redir.file, O_RDONLY, STDIN_FILENO))
            return (false);
    }
    else if (redir.type == OP_REDIR_OUT)
    {
        if (open_redirect((char *)redir.file,
                    O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO))
            return (false);
    }
    else if (redir.type == OP_APPEND)
    {
        if (open_redirect((char *)redir.file,
                    O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO))
            return (false);
    }
    else if (redir.type == OP_HEREDOC)
    {
        redirect_heredoc((t_heredoc *)redir.file);
    }
    return (true);
}

static bool pickup_redirection(t_redir *redir, int n_redirs)
{
    size_t i = 0;

    i = 0;
    while (i < (size_t)n_redirs)
    {
        if (!check_redirection(redir[i]))
            return (false);
        i++;
    }
    return (true);
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

bool redirection_setup(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;

    if (get_redirs(branch, &redirs, &n_redirs))
    {
        if (!pickup_redirection(redirs, n_redirs))
            return (_exit_status(UPDATE, 1), false);
    }
    return (true);
}

bool open_redirections(t_redir *redirs, int n_redirs)
{
    size_t  i;
    int     fd;
    int     *fdp;
    char    *fname;
    int     flags;

    i = 0;
    while (i < (size_t)n_redirs)
    {
        if (redirs[i].type == OP_HEREDOC)
        {
            i++;
            continue;
        }

        else
        {
            cleanup_opened_redirs(redirs, i);
            return (false);
        }
        fd = create_open((char *)redirs[i].file, flags, 0644);
        if (fd < 0)
        {
            cleanup_opened_redirs(redirs, i);
            (void)return_failure(fname);
            return (false);
        }
        fdp = malloc(sizeof(int));
        if (!fdp)
        {
            close_and_remove(fd);
            cleanup_opened_redirs(redirs, i);
            return (false);
        }
        *fdp = fd;
        free(fname);
        redirs[i].file = (void *)fdp;
        i++;
    }
    return (true);
}