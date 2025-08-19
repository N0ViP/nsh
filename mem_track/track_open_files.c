#include "mem_track.h"

static void save_to_shell_fds(int fd)
{
    int     **fds;
    int     cap;
    int     cnt;

    fds = shell_fds();
    cap = (*fds)[0];
    cnt = (*fds)[1];
    if (cnt == cap)
    {
        cap *= INITIAL_CAPACITY;
        set_current_section(REMAINS);
        *fds = ft_realloc(*fds, cnt * sizeof(int), cap * sizeof(int));
        set_current_section(GLOBALE);
        (*fds)[0] = cap;
    }
    (*fds)[cnt] = fd;
    (*fds)[1]++;
}

int open_file(char *path, int flags, mode_t mode)
{
    int fd;

    fd = open(path, flags, mode);
    if (fd > 0)
    {
        save_to_shell_fds(fd);
    }
    return (fd);
}

int open_readonly_file(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd > 0)
    {
        save_to_shell_fds(fd);
    }
    return (fd);
}
