#include "mem_track.h"

t_section *find_section(t_section *section, t_sid section_id)
{
    if (!section)
        return (NULL);
    if (section->section_id == section_id)
        return (section);
    return (find_section(section->next, section_id));
}

t_section *find_or_create_section(t_sid section_id)
{
    t_section *section;

    section = find_section(*get_sections(), section_id);
    if (!section)
        return (create_section(section_id));
    return (section);
}
