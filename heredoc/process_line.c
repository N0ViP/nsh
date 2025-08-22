/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:25:01 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:25:02 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static bool	is_delimiter(char *line, char *delimiter)
{
	if (!line)
		return (true);
	if (ft_strlen(line) == ft_strlen(delimiter) && !ft_strcmp(line, delimiter))
	{
		free(line);
		return (true);
	}
	return (false);
}

bool	process_line(int wfd, char *line, char *delimiter)
{
	if (is_delimiter(line, delimiter))
		return (true);
	if (*line)
		write(wfd, line, ft_strlen(line));
	write(wfd, "\n", 1);
	return (false);
}
