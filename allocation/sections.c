#include "allocation.h"

t_section **get_sections(void)
{
    static t_section *pointer_to_sections = NULL;
    return (&pointer_to_sections);
}

t_section *find_section(t_section *section, const char *name)
{
    if (!section)
        return NULL;
    if (!ft_strcmp(section->section_name, (char *)name))
        return (section);
    return (find_section(section->next, name));
}

t_section *create_section(const char *name)
{
    t_section *section;

    section = smalloc(sizeof(t_section));
    section->section_name = ft_strndup(name, ft_strlen(name));
    section->allocations = malloc(sizeof(void *) * ALLOCATION_CAPACITY);
    section->count = 0;
    section->capacity = ALLOCATION_CAPACITY;
    section->next = *get_sections();
    *get_sections() = section;
    return (section);
}
