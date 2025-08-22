/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_open_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:37 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:38 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

static void	save_to_shell_fds(int fd)
{
	int	**fds;
	int	cap;
	int	cnt;

	fds = shell_fds();
	cap = (*fds)[0];
	cnt = (*fds)[1];
	if (cnt == cap)
	{
		cap *= INITIAL_CAPACITY;
		set_current_section(REMAINS);
		*fds = ft_realloc(*fds, cnt * sizeof(int), cap * sizeof(int));
		set_current_section(GLOBALE);
		(*fds)[0] = cap;
	}
	(*fds)[cnt] = fd;
	(*fds)[1]++;
}

int	create_open(char *path, int flags, mode_t mode)
{
	int	fd;

	flags |= O_CLOEXEC;
	fd = open(path, flags, mode);
	if (fd > 0)
	{
		save_to_shell_fds(fd);
	}
	return (fd);
}

int	open_readonly(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY | O_CLOEXEC);
	if (fd > 0)
	{
		save_to_shell_fds(fd);
	}
	return (fd);
}

bool	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
	{
		return (false);
	}
	save_to_shell_fds(pipefd[0]);
	save_to_shell_fds(pipefd[1]);
	return (true);
}

int	duplicate_fd(int fd)
{
	int	saved;

	saved = dup(fd);
	if (saved > 0)
	{
		save_to_shell_fds(saved);
	}
	return (saved);
}
