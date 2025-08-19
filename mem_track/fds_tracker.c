#include "mem_track.h"

int **shell_fds(void)
{
    static int *fds = NULL;
    return &fds;
}

void init_fds(void)
{
    int     **fds;

    fds = shell_fds();
    *fds = new_allocation(REMAINS, (INITIAL_CAPACITY) * sizeof(int));
    (*fds)[0] = INITIAL_CAPACITY;
    (*fds)[1] = 2;
}
