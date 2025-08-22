/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:25:11 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:25:12 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

bool	write_to_heredoc(int wfd, char *delimiter)
{
	char	*line;

	while (g_signaled == 0)
	{
		line = readline("> ");
		if (process_line(wfd, line, delimiter))
			break ;
		free(line);
	}
	return (g_signaled == SIGINT);
}
