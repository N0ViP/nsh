#include "allocation.h"

void *new_allocation(const char *section_name, size_t size)
{
    void *pointer;

    pointer = smalloc(size);
    add_allocation_to_section(section_name, pointer);
    return (pointer);
}

void add_allocation_to_section(const char *section_name, void *ptr)
{
    void        ***allocs;
    t_section   *section;
    size_t      *cap;
    size_t      *cnt;

    section = find_or_create_section(section_name);
    allocs = &section->allocations;
    cap = &section->capacity;
    cnt = &section->count;
    if (*cnt == *cap)
    {
        *cap *= ALLOCATION_CAPACITY;
        *allocs = ft_realloc(*allocs, *cnt, *cap * sizeof(void *));
    }
    (*allocs)[*cnt] = ptr;
    (*cnt)++;
}
