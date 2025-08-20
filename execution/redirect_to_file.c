# include "execution.h"

void redirect_heredoc(t_heredoc *heredoc)
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
bool open_redirect(char *file, int flags, int target_fd)
{
    int fd;
    
    fd = create_open(file, flags, 0644);
    if (fd < 0)
        return (return_failure(file));
    dup2(fd, target_fd);
    close_and_remove(fd);
    return (false);
}
