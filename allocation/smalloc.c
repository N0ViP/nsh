#include "allocation.h"

void *smalloc(size_t size)
{
    void *pointer;

    pointer = malloc(size);
    if (!pointer)
    {
        exit_failure("malloc");
    }
    return (pointer);
}
