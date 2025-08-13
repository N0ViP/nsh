#include "allocation.h"

static t_section *recurse_skip_env(t_section *section)
{
    t_section *env_section;

    if (!section)
        return (NULL);
    env_section = recurse_skip_env(section->next);
    if (section->section_id == EVIRON)
        return (section->next = NULL, section);
    clear_section_data(section);
    return (env_section);
}

void clean_before_prompt(void)
{
    t_section **sections;

    sections = get_sections();
    *sections = recurse_skip_env(*sections);
}
