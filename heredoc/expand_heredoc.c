# include "heredoc.h"

int expanded_heredoc_file(int old_rfd)
{
    size_t length;
    char *buffer;
    int wfd;
    int rfd;

    if (!create_file(&wfd, &rfd))
        return (-1);
    if (!read_file_into_buffer(old_rfd, &buffer, &length))
        return (-1);
    write_line_by_line(wfd, buffer, length);
    return (rfd);
}
