#include "allocation.h"

void *smalloc(size_t size)
{
    void *pointer;

    pointer = malloc(size);
    if (!pointer)
    {
        destroy_all_sections();
        exit_failure("malloc");
    }
    return (pointer);
}

void *new_allocation(const char *section_name, size_t size)
{
    void        ***allocs;
    void        *pointer;
    t_section   *section;
    size_t      *cap;
    size_t      *cnt;

    section = find_section(*get_sections(), section_name);
    if (!section)
        return (NULL);
    allocs = &section->allocations;
    cap = &section->capacity;
    cnt = &section->count;
    if (*cnt == *cap)
    {
        *cap *= ALLOCATION_CAPACITY;
        *allocs = ft_realloc(*allocs, *cnt, *cap * sizeof(void *));
    }
    pointer = smalloc(size);
    (*allocs)[*cnt] = pointer;
    (*cnt)++;
    return (pointer);
}
