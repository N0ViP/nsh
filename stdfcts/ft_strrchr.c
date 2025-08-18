#include "utils.h"

char    *ft_strrchr(const char *s, int c)
{
    const char  *last = NULL;

    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    if ((char)c == '\0')
        return (char *)s;
    return ((char *)last);
}
