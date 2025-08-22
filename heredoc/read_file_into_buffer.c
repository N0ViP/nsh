/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_into_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:25:04 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:25:05 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	increase_capacity(char **b, ssize_t r_b, size_t *l, size_t *c)
{
	ssize_t	read_bytes;
	size_t	*capacity;
	char	**buffer;
	size_t	*length;

	length = l;
	buffer = b;
	capacity = c;
	read_bytes = r_b;
	*length += (size_t)read_bytes;
	if (length == capacity)
	{
		*capacity *= 2;
		*buffer = ft_realloc(*buffer, *length, *capacity + 1);
	}
	return ;
}

bool	read_file_into_buffer(int old_rfd, char **buffer, size_t *length)
{
	ssize_t	read_bytes;
	size_t	capacity;

	*length = 0;
	capacity = INITIAL_CAPACITY;
	*buffer = allocate_memory(capacity + 1);
	while (true)
	{
		read_bytes = read(old_rfd, *buffer + *length, capacity - *length);
		if (read_bytes > 0)
		{
			increase_capacity(buffer, read_bytes, length, &capacity);
			continue ;
		}
		if (read_bytes < 0)
			return (false);
		if (!read_bytes)
			break ;
	}
	close_and_remove(old_rfd);
	(*buffer)[*length] = '\0';
	return (true);
}
