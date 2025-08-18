# include "heredoc.h"

static bool is_delimiter(char *line, char *delimiter)
{
    if (!line)
        return (true);
    if (ft_strlen(line) == ft_strlen(delimiter)
        && !ft_strcmp(line, delimiter))
    {
        free(line);
        return (true);
    }
    return (false);
}

bool process_line(int wfd, char *line, char *delimiter)
{
    if (is_delimiter(line, delimiter))
        return (true);
    if (*line)
        write(wfd, line, ft_strlen(line));
    write(wfd, "\n", 1);
    return (false);
}
