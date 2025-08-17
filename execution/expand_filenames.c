#include "execution.h"

static bool ambiguous_redirect(char *arg)
{
	_exit_status(UPDATE, EXIT_FAILURE);
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, ": ambiguous redirect\n", 20);
	return (false);
}

static bool expand_and_check(t_redir *redirs, int n_redirs)
{
	t_list_info		*arg_list;
	size_t			i;

	i = 0;
	while (i < (size_t)n_redirs)//make it size_t
	{
		if (redirs[i].type != OP_HEREDOC)
		{
			arg_list = expander((char *)redirs[i].file);
			if (arg_list->size != 1)
				return (ambiguous_redirect((char *)redirs[i].file));
			redirs->file = arg_list->list->content;
		}
		i++;
	}
	return (true);
}

bool expand_filenames(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;

    if (get_redirs(branch, &redirs, &n_redirs))
    {
        return (expand_and_check(redirs, n_redirs));
    }
	return (true);
}
