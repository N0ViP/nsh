# include "heredoc.h"

static void copy_new_delemiter(char **delimiter, size_t new_len)
{
    char    *new_dlm;
    char    *dlm;

    new_dlm = allocate_memory(new_len + 1);
    dlm = *delimiter;
    *delimiter = new_dlm;
    while (*dlm)
    {
        if (*dlm != '"' && *dlm != '\'')
            *new_dlm++ = *dlm;
        dlm++;
    }
    *new_dlm = '\0';
}

bool look_for_quotes(char **delimiter)
{
    bool    was_quoted;
    size_t  new_len;
    char    *dlm;


    new_len = 0;
    dlm = *delimiter;
    was_quoted = false;
    while (*dlm)
    {
        if (!was_quoted && (*dlm == '"' || *dlm == '\''))
        {
            was_quoted = true;
        }
        else if (!(*dlm == '"' || *dlm == '\''))
        {
            new_len++;
        }
        dlm++;
    }
    copy_new_delemiter(delimiter, new_len);
    return (was_quoted);
}
