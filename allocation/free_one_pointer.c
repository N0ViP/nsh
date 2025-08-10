#include "allocation.h"

void free_one_pointer(const char *section_name, void *pointer)
{
    t_section   *section;
    void        **allocs;
    size_t      cnt;

    section = find_section(*get_sections(), section_name);
    if (!section)
        return ;
    allocs = section->allocations;
    cnt = section->count;
    while (cnt--)
    {
        if (allocs[cnt] == pointer)
        {
            free(pointer);
            (section->count)--;
            allocs[cnt] = allocs[section->count];
            return ; 
        }
    }
}
