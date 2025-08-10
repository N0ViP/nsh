#include "allocation.h"

static t_section *recursive_search(t_section **section, const char *name)
{
    t_section *to_destroy;

    if (!*section)
        return (NULL);
    if (!ft_strcmp((*section)->section_name, (char *)name))
    {
        to_destroy = *section;
        *section = to_destroy->next;
        return (to_destroy);
    }
    return (recursive_search(&(*section)->next, name));
}

void destroy_section(const char *name)
{
    t_section *section;

    section = recursive_search(get_sections(), name);
    clear_section_data(section);    
}