#include "allocation.h"

static t_section *recursive_search(t_section **section, t_sid section_id)
{
    t_section *to_destroy;

    if (!*section)
        return (NULL);
    if ((*section)->section_id == section_id)
    {
        to_destroy = *section;
        *section = to_destroy->next;
        return (to_destroy);
    }
    return (recursive_search(&(*section)->next, section_id));
}

void destroy_section(t_sid section_id)
{
    t_section *section;

    section = recursive_search(get_sections(), section_id);
    clear_section_data(section);    
}