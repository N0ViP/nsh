#include "allocation.h"

void add_allocation_to_section(t_sid section_id, void *ptr)
{
    void        **allocs;
    t_section   *section;
    size_t      *cap;
    size_t      *cnt;
    section = find_or_create_section(section_id);
    allocs = section->allocations;
    cap = &section->capacity;
    cnt = &section->count;
    if (*cnt == *cap)
    {
        *cap *= ALLOCATION_CAPACITY;
        allocs = realloc(allocs, *cap * sizeof(void *));//
        section->allocations = allocs;
    }
    allocs[*cnt] = ptr;
    (*cnt)++;
}

void add_allocations_to_section(t_sid section_id, void **ptr)
{
    add_allocation_to_section(section_id, ptr);
    while (*ptr)
        add_allocation_to_section(section_id, *ptr++);
}
