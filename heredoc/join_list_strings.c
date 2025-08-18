# include "heredoc.h"

static size_t compute_total(t_list  *node)
{
    size_t  total;
    size_t  count;

    total = 0;
    count = 0;
    while (node)
    {
        if (node->content)
            total += ft_strlen((char *)node->content);
        count++;
        node = node->next;
    }
    if (count > 1)
        total += (count - 1);
    return (total);
}

char    *join_list_strings(t_list_info *info)
{
    t_list              *node;
    size_t              total;
    char                *joined_strings;

    if (!info || !info->list)
        return (allocate_retval(PARSING, ""));

    node = info->list;

    total = compute_total(node);

    joined_strings = new_allocation(PARSING, total + 1);
    join_string(node, joined_strings, total);
    return (joined_strings);
}
