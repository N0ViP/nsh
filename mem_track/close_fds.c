/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:06 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:07 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

static int	find_fd(int fd)
{
	int	**fds;
	int	cnt;

	fds = shell_fds();
	cnt = (*fds)[1];
	while ((--cnt) >= 2)
	{
		if ((*fds)[cnt] == fd)
			return (cnt);
	}
	return (-1);
}

void	close_and_remove(int fd)
{
	int	**fds;
	int	idx;

	fds = shell_fds();
	idx = find_fd(fd);
	if (idx < 2)
		return ;
	(*fds)[1]--;
	if (idx != (*fds)[1])
		(*fds)[idx] = (*fds)[(*fds)[1]];
	close(fd);
}

void	close_everything(void)
{
	int	**fds;
	int	cnt;

	fds = shell_fds();
	cnt = (*fds)[1];
	while ((--cnt) >= 2)
	{
		close((*fds)[cnt]);
	}
	return ;
}
