# include "execution.h"

static void redirect_heredoc(t_heredoc *heredoc)
{
    int rfd;

    if (!heredoc || heredoc->rfd < 0)
        return ;
    rfd = heredoc->rfd;
    if (!heredoc->was_quoted)
        rfd = expanded_heredoc_file(rfd);
    if (rfd >= 0)
    {
        dup2(rfd, STDIN_FILENO);
        close_and_remove(rfd);
    }
}

static bool open_redirect(char *file, int flags, int target_fd)
{
    int fd;
    
    fd = create_open(file, flags, 0644);
    if (fd < 0)
        return (return_failure(file));
    dup2(fd, target_fd);
    close_and_remove(fd);
    return (false);
}
static bool pickup_redirection(t_redir *redir, int n_redirs)
{
    for (int i = 0; i < n_redirs; i++)
    {
        if (redir[i].type == OP_REDIR_IN)
        {printf("[DEBUG] Opening redirection '%s' of type %d\n", (char *)redir[i].file, redir[i].type);
            if (open_redirect((char *)redir[i].file, O_RDONLY, STDIN_FILENO))
                return false;
        }
        else if (redir[i].type == OP_REDIR_OUT)
        {printf("[DEBUG] Opening redirection '%s' of type %d\n", (char *)redir[i].file, redir[i].type);
            if (open_redirect((char *)redir[i].file, O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO))
                return false;
        }
        else if (redir[i].type == OP_APPEND)
        {printf("[DEBUG] Opening redirection '%s' of type %d\n", (char *)redir[i].file, redir[i].type);
            if (open_redirect((char *)redir[i].file, O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO))
                return false;
        }
        else if (redir[i].type == OP_HEREDOC)
        {printf("[DEBUG] Opening redirection '%s' of type %d\n", (char *)redir[i].file, redir[i].type);
            redirect_heredoc((t_heredoc *)redir[i].file);
        }
        else    printf("[DEBUG] Opening redirection '%s' of type %d\n", (char *)redir[i].file, redir[i].type);
    }
    return true;
}
// static bool pickup_redirection(t_redir *redir, int n_redirs)
// {
//     bool    failure;
//     int     i;

//     i = 0;
//     failure = false;
//     while(i < n_redirs)
//     {
//         if (redir[i].type == OP_REDIR_IN)
//             failure = open_redirect((char *)redir[i].file,
//                         O_RDONLY, STDIN_FILENO);
//         else if (redir[i].type == OP_REDIR_OUT)
//             failure = open_redirect((char *)redir[i].file,
//                         O_WRONLY | O_CREAT | O_TRUNC, 
//                         STDOUT_FILENO);
//         else if (redir[i].type == OP_APPEND)
//             failure = open_redirect((char *)redir[i].file,
//                         O_WRONLY | O_CREAT | O_APPEND,
//                         STDOUT_FILENO);
//         else if (redir[i].type == OP_HEREDOC)
//             redirect_heredoc((t_heredoc *)redir[i].file);
//         if(failure)
//             return (false);
//         i++;
//     }
//     return (true);
// }

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