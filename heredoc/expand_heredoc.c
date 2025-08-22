/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:38 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:24:39 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	expanded_heredoc_file(int old_rfd)
{
	size_t	length;
	char	*buffer;
	int		wfd;
	int		rfd;

	if (!create_file(&wfd, &rfd))
		return (-1);
	if (!read_file_into_buffer(old_rfd, &buffer, &length))
		return (-1);
	write_line_by_line(wfd, buffer, length);
	return (rfd);
}
