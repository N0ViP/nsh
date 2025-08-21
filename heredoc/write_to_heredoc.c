# include "heredoc.h"

bool write_to_heredoc(int wfd, char *delimiter)
{
    char    *line;

    while (g_signaled == 0)
    {
        line = readline("> ");
        if (process_line(wfd, line, delimiter))
            break;
        free(line);
    }
    return (g_signaled == SIGINT);
}
