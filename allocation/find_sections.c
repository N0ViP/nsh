#include "allocation.h"

t_section *find_section(t_section *section, const char *name)
{
    if (!section)
        return NULL;
    if (!ft_strcmp(section->section_name, (char *)name))
        return (section);
    return (find_section(section->next, name));
}

t_section *find_or_create_section(const char *section_name)
{
    t_section *section;

    section = find_section(*get_sections(), section_name);
    if (!section)
        return (create_section(section_name));
    return (section);
}
