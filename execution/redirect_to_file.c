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

void dup_redirections(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;
    int     dup_fd;
    int     fd;
    size_t  i;

    if (get_redirs(branch, &redirs, &n_redirs))
    {
        i = -1;
        while (++i < (size_t)n_redirs)
        {
            if (redirs[i].type == OP_HEREDOC)
            {
                redirect_heredoc((t_heredoc *)redirs[i].file);
                continue;
            }
            dup_fd = STDOUT_FILENO;
            fd = *(int *)redirs[i].file;
            if (redirs[i].type == OP_REDIR_IN)
                dup_fd = STDIN_FILENO;
            dup2(fd, dup_fd);
            close_and_remove(fd);
        }            
    }
}
