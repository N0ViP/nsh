# include "heredoc.h"

static void increase_capacity(char **b, ssize_t r_b, size_t *l, size_t *c)
{
    ssize_t read_bytes;
    size_t  *capacity;
    char    **buffer;
    size_t  *length;

    length = l;
    buffer = b;
    capacity = c;
    read_bytes = r_b;            
    *length += (size_t)read_bytes;            
    if (length == capacity)
    {
        *capacity *= 2;
        *buffer = ft_realloc(*buffer,
                            *length * sizeof(char *),
                            (*capacity + 1)  * sizeof(char *));
    }
    return ;
}

bool read_file_into_buffer(int old_rfd, char **buffer, size_t *length)
{
    ssize_t read_bytes;
    size_t  capacity;

    capacity = ARENA_SIZE;
    *buffer = allocate_memory(capacity + 1);
    while (true)
    {
        read_bytes = read(old_rfd, *buffer + *length, capacity - *length);
        if (read_bytes > 0)
        {
            increase_capacity(buffer, read_bytes, length, &capacity);
            continue;
        }
        if (read_bytes < 0)
            return (false);
        if (!read_bytes)
            break;
    }
    close_and_remove(old_rfd);
    (*buffer)[*length] = '\0';
    return (true);
}
