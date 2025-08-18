# include "heredoc.h"

static t_heredoc *get_heredoc_infos(char *delimiter)
{
    t_heredoc   *heredoc;
    bool        was_quoted;
    int         fd;

    was_quoted = look_for_quotes(&delimiter);
    fd = open_heredoc(delimiter);
    if (fd < 0)
        return (NULL);
    heredoc = new_allocation(EXECUTION, sizeof(t_heredoc));
    heredoc->was_quoted = was_quoted;
    heredoc->rfd = fd;
    return (heredoc);
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
            redirs[i].file = get_heredoc_infos(redirs[i].file);//return null!!
    return (heredoc_exit);
}
