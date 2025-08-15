# include "execution.h"

static void redirect_heredoc(int *fd)
{
    if (!fd)
        return ;
    dup2(*fd, STDIN_FILENO);
    close(*fd);
}

static void open_redirect(char *file, int flags, int target_fd)
{
    int fd;
    
    fd = open(file, flags, 0644);
    if (fd < 0)
        exit_failure((char *)file);
    if (dup2(fd, target_fd) < 0)
        exit_failure("dup2");
    close(fd);
}

static void pickup_redirection(t_redir *redir, int n_redirs)
{
    int i;

    i = 0;
    while(i < n_redirs)
    {
        if (redir[i].type == OP_REDIR_IN)
            open_redirect((char *)redir[i].file,
                        O_RDONLY, STDIN_FILENO);
        else if (redir[i].type == OP_REDIR_OUT)
            open_redirect((char *)redir[i].file,
                        O_WRONLY | O_CREAT | O_TRUNC, 
                        STDOUT_FILENO);
        else if (redir[i].type == OP_APPEND)
            open_redirect((char *)redir[i].file,
                        O_WRONLY | O_CREAT | O_APPEND,
                        STDOUT_FILENO);
        else if (redir[i].type == OP_HEREDOC)
            redirect_heredoc((int *)redir[i].file);
        i++;
    }
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
    // if(branch->type == COMMAND)
    // {
    //     redir = expand_file_name(&branch->data.cmd);
    //     n_redirs = branch->data.cmd.n_redirs;
    // }
    // else if(branch->type == SUBSHELL)
    // {
    //     redir = expand_file_name(&branch->data.cmd);
    //     n_redirs = branch->data.subshell.n_redirs;
    // }
    return (*n_redirs > 0);
}

void redirection_setup(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;

    if (get_redirs(branch, &redirs, &n_redirs))
        pickup_redirection(redirs, n_redirs);
}
