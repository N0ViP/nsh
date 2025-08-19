#include "mem_track.h"

void free_one_pointer(t_sid section_id, void *pointer)
{
    t_section   *section;
    void        **allocs;
    size_t      cnt;

    section = find_section(*get_sections(), section_id);
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
