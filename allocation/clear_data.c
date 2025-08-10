#include "allocation.h"

void clear_section_data(t_section *section)
{
    size_t cnt;

    if (!section)
        return ;
    cnt = section->count;
    while (cnt--)
        free(section->allocations[cnt]);
    free(section->allocations);
    free(section->section_name);
    free(section);
}
