#include "mem_track.h"

static void recursive_destruction(t_section *section)
{
    if (!section)
        return ;
    recursive_destruction(section->next);
    clear_section_data(section);
}

void destroy_everything(void)
{
    t_section **sections;

    sections = get_sections();
    recursive_destruction(*sections);
    *sections = NULL;
}
