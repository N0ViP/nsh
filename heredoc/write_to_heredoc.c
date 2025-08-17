# include "heredoc.h"

bool write_to_heredoc(int wfd, char *delimiter)
{
    char    *line;
    bool    was_quoted;

    was_quoted = look_for_quotes(&delimiter);
    while (heredoc_exit == 0)
    {
        line = readline("> ");// history
        if (process_line(wfd, line, was_quoted, delimiter))
            break;
        free(line);
    }
    return (heredoc_exit == 130);
}
