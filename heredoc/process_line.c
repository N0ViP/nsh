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

static void write_expanded_line(int wfd, char *line)
{
    t_list_info *list;
    char        *expanded;

    list = expander(line);
    expanded = join_list_strings(list);
    if (expanded && *expanded)
    {
        write(wfd, expanded, ft_strlen(expanded));
    }
}

bool process_line(int wfd, char *line, bool was_quoted, char *delimiter)
{
    if (is_delimiter(line, delimiter))
        return (true);
    if (was_quoted)
    {
        if (*line)
            write(wfd, line, ft_strlen(line));
    }
    else
    {
        if (*line)
            write_expanded_line(wfd, line);
    }
    write(wfd, "\n", 1);
    return (false);
}
