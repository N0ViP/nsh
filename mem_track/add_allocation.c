#include "mem_track.h"

void	*reallocate_memory(void *pointer, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	min;

	new_ptr = smalloc(new_size);
	min = ft_min(old_size, new_size);
	ft_memcpy(new_ptr, pointer, min);
	free(pointer);
	return (new_ptr);
}

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
        *cap *= INITIAL_CAPACITY;
        allocs = reallocate_memory(allocs,
                                    *cnt * sizeof(void *),
                                    *cap * sizeof(void *));
        section->allocations = allocs;
    }
    allocs[*cnt] = ptr;
    (*cnt)++;
}

void add_allocation(void *pointer)
{
    add_allocation_to_section(*current_section(), pointer);
}
