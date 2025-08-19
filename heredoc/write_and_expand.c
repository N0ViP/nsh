# include "heredoc.h"

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
    return ;
}

void write_line_by_line(int wfd, char *buffer, size_t length)
{
    size_t  idx;
    size_t  start;
    size_t  line_len;
    char    *line;

    idx = 0;
    start = 0;
    while (idx <= length && start < length)
    {
        if (buffer[idx] == '\n' || idx == length)
        {
            line_len = (idx + 1) - start;
            line = allocate_memory(line_len + 1);
            ft_memcpy(line, buffer + start, line_len);
            line[line_len] = '\0';
            write_expanded_line(wfd, line);
            start = idx + 1;
        }
        idx++;
    }
    close(wfd);
    free_one_pointer(*current_section(), buffer);
}
