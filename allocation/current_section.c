#include "allocation.h"

t_sid *current_section(void)
{
    static t_sid current_section_id = TOKENIZE;
    return (&current_section_id);
}

void set_current_section(t_sid updated_section_id)
{
    t_sid *current_section_id;

    current_section_id = current_section();
    *current_section_id = updated_section_id;
}