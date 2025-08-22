/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filenames.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:13 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:20:35 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static bool	ambiguous_redirect(char *arg)
{
	_exit_status(UPDATE, EXIT_FAILURE);
	write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, ": ambiguous redirect\n", 21);
	return (false);
}

static bool	expand_and_check(t_redir *redirs, int n_redirs)
{
	t_list_info	*arg_list;
	size_t		i;

	i = 0;
	while (i < (size_t)n_redirs)
	{
		if (redirs[i].type != OP_HEREDOC)
		{
			arg_list = expander((char *)redirs[i].file);
			if (arg_list->size != 1)
				return (ambiguous_redirect((char *)redirs[i].file));
			redirs[i].file = arg_list->list->content;
		}
		i++;
	}
	return (true);
}

bool	expand_filenames(t_tree *branch)
{
	t_redir	*redirs;
	bool	failure;
	int		n_redirs;

	if (get_redirs(branch, &redirs, &n_redirs))
	{
		failure = expand_and_check(redirs, n_redirs);
		if (!failure || !open_redirections(redirs, n_redirs))
			return (_exit_status(UPDATE, 1), false);
	}
	return (true);
}
