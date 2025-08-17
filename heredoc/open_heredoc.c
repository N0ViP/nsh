# include "heredoc.h"

static int	open_heredoc_write_read(char *tty_name, int *wfd, int *rfd)
{
    static unsigned int counter = INT_MAX;
	char			    *heredoc_name;
	int				    tries;

	tries = 0;
	while (tries++ < 1000)
	{
		heredoc_name = compose_name("/tmp/nsh_",
                                    tty_name,
                                    counter--,
                                    ".heredoc");
		*wfd = open(heredoc_name, O_CREAT | O_EXCL | O_RDWR, 0600);
		if (*wfd >= 0)
		{
            *rfd = open(heredoc_name, O_RDONLY);
            if (*rfd >= 0)
			    return (unlink(heredoc_name), false);
		}
	}
    unlink(heredoc_name);
	return (true);
}

int open_heredoc(char *delimiter)
{
    char    *tty_name;
    bool    fail_check;
    int     wfd;
    int     rfd;

    tty_name = get_tty_name();
    if (!tty_name)
        tty_name = num_to_str((unsigned long)&tty_name);
    fail_check = open_heredoc_write_read(tty_name, &wfd, &rfd);
    if (fail_check)
        return (-1);
    heredoc_signals();
    fail_check = write_to_heredoc(wfd, delimiter);
    close(wfd);
    shell_signals();
    if (fail_check)
        return (-1);
    return (rfd);
}
