#include "allocation.h"

t_section **get_sections(void)
{
    static t_section *pointer_to_sections = NULL;
    return (&pointer_to_sections);
}

t_section *create_section(t_sid section_id)
{
    t_section *section;

    section = smalloc(sizeof(t_section));
    section->section_id = section_id;
    section->allocations = smalloc(sizeof(void *) * ALLOCATION_CAPACITY);
    section->count = 0;
    section->capacity = ALLOCATION_CAPACITY;
    section->next = *get_sections();
    *get_sections() = section;
    return (section);
}
