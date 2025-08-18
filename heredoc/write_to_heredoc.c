# include "heredoc.h"

bool write_to_heredoc(int wfd, char *delimiter)
{
    char    *line;

    while (heredoc_exit == 0)
    {
        line = readline("> ");// history
        if (process_line(wfd, line, delimiter))
            break;
        free(line);
    }
    return (heredoc_exit == 130);
}
