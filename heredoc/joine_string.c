# include "heredoc.h"

void joine_string(t_list  *node, char *to_fill, size_t total)
{
    char    *content;
    size_t  len;

    while (node)
    {
        content = (char *)node->content;
        if (content)
        {
            len = ft_strlen(content);
            if (len > 0)
            {
                ft_memcpy(to_fill, content, len);
                to_fill += len;
                total -= len;
            }
        }
        if (node->next && total)
        {
            *to_fill = ' ';
            to_fill++;
            total--;
        }
        node = node->next;
    }
    *to_fill = '\0';
}
