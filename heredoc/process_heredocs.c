/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:59 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:40:20 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static t_heredoc	*get_heredoc_infos(char *delimiter)
{
	t_heredoc	*heredoc;
	bool		was_quoted;
	int			fd;

	was_quoted = look_for_quotes(&delimiter);
	fd = open_heredoc(delimiter);
	if (fd < 0)
		return (NULL);
	heredoc = allocate_memory(sizeof(t_heredoc));
	heredoc->was_quoted = was_quoted;
	heredoc->rfd = fd;
	return (heredoc);
}

int	process_heredocs(t_tree *branch)
{
	t_redir	*redirs;
	int		n_redirs;
	int		i;

	i = -1;
	if (!get_redirs(branch, &redirs, &n_redirs))
		return (EXIT_SUCCESS);
	while (++i < n_redirs && !g_signaled)
		if (redirs[i].type == OP_HEREDOC)
			redirs[i].file = get_heredoc_infos(redirs[i].file);
	return (_exit_status(EXTRACT, 0));
}
