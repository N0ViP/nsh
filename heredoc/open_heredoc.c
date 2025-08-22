/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:55 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:24:56 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static bool	open_write_read(char *tty_name, int *wfd, int *rfd)
{
	static unsigned int	counter = INT_MAX;
	char				*heredoc_name;
	int					tries;

	tries = 0;
	while (tries++ < 1000)
	{
		heredoc_name = compose_name("/tmp/nsh_", tty_name, counter--,
				".heredoc");
		*wfd = create_open(heredoc_name, O_CREAT | O_EXCL | O_RDWR, 0600);
		if (*wfd >= 0)
		{
			*rfd = open_readonly(heredoc_name);
			if (*rfd >= 0)
				return (unlink(heredoc_name), true);
		}
	}
	unlink(heredoc_name);
	return (false);
}

bool	create_file(int *wfd, int *rfd)
{
	char	*tty_name;

	tty_name = get_tty_name();
	if (!tty_name)
		tty_name = num_to_str((unsigned long)&tty_name);
	return (open_write_read(tty_name, wfd, rfd));
}

int	open_heredoc(char *delimiter)
{
	bool	interrupted;
	int		wfd;
	int		rfd;

	if (!create_file(&wfd, &rfd))
		return (-1);
	heredoc_mode_signals();
	interrupted = write_to_heredoc(wfd, delimiter);
	parent_mode_signals();
	close_and_remove(wfd);
	if (interrupted)
		return (-1);
	return (_exit_status(UPDATE, 0), rfd);
}
