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
