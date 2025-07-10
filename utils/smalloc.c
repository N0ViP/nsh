#include "utils.h"

void *smalloc(size_t n)
{
    void *pointer;

    pointer = malloc(n);
    if (!pointer)
    {
        perror("malloc");
        exit(EXIT_FAILURE); 
    }
    return pointer;
}
