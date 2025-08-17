# include "heredoc.h"

static int *get_heredoc_fd(char *delimiter)
{
    int *pointer;
    int fd;

    fd = open_heredoc(delimiter);
    if (fd < 0)
        return (NULL);
    pointer = new_allocation(EXECUTION, sizeof(int));
    *pointer = fd;
    return (pointer);
}

int process_heredocs(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;
    int     i;

    i = -1;
    heredoc_exit = 0;
    if (!get_redirs(branch, &redirs, &n_redirs))
        return (heredoc_exit);
    while(++i < n_redirs && !heredoc_exit)
        if (redirs[i].type == OP_HEREDOC)
            redirs[i].file = get_heredoc_fd(redirs[i].file);//return null!!
    return (heredoc_exit);
}
