# include "heredoc.h"

char *get_tty_name(void)
{
    char *tty, *name;


    if (!isatty(STDIN_FILENO))//add it at the begining
        return (NULL);
    tty = ttyname(STDIN_FILENO);
    if (!tty)
        return (NULL);
    name = ft_strrchr(tty, '/');
    if(name)
        name++;
    else
        name = tty;
    return (ft_strdup(name));
}

char *compose_name(char *prefix, char *tty_name, size_t counter, char *sufix)
{
    char    *counter_s;
    size_t  tty_len;
    size_t  cnt_len;
    char    *name;
    char    *ptr;

    counter_s = num_to_str(counter);
    tty_len = ft_strlen(tty_name);
    cnt_len = ft_strlen(counter_s);
    name = allocate_memory(tty_len + cnt_len + 19);
    ptr = name;
    ft_memcpy(ptr, prefix, 9);
    ptr += 9;
    ft_memcpy(ptr, tty_name, tty_len);
    ptr += tty_len;
    *ptr++ = '_';
    ft_memcpy(ptr, counter_s, cnt_len);
    ptr += cnt_len;
    ft_memcpy(ptr, sufix, 8);
    ptr += 8;
    *ptr = '\0';
    return (name);
}
