#include "allocation.h"

void *allocate_memory(size_t size)
{
    void *pointer;

    pointer = smalloc(size);
    add_allocation_to_section(*current_section(), pointer);
    return (pointer);
}

void *new_allocation(t_sid section_id, size_t size)
{
    void *pointer;

    pointer = smalloc(size);
    add_allocation_to_section(section_id, pointer);
    return (pointer);
}

// char *allocate_retval(t_sid section_id, char *to_copy)
// {
// 	char *retval;

// 	retval = ft_strdup(to_copy);
// 	add_allocation_to_section(section_id, retval);
// 	return (retval);
// }
