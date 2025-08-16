# include "execution.h"

int heredoc_exit = 0;

static char *get_tty_name(void)
{
    char *tty, *name;


    if (!isatty(STDIN_FILENO))//add it at the begining
        return (NULL);
    tty = ttyname(STDIN_FILENO);
    if (!tty)
        return (NULL);
    name = ft_strrchr(tty, '/');
    if(name)
        name++;
    else
        name = tty;
    return (allocate_retval(EXECUTION, name));
}

static char	*num_to_str(unsigned long v)
{
	unsigned long	tmp;
	int				digits;
	char			*s;

	tmp = v;
	digits = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	s = new_allocation(EXECUTION, digits + 1);
	s[digits] = '\0';
	while (digits > 0)
	{
		digits--;
		s[digits] = '0' + (v % 10);
		v /= 10;
	}
	return (s);
}

static char *compose_name(char *tty_name, char *prefix, char *sufix, size_t counter)
{
    char    *counter_s;
    size_t  tty_len;
    size_t  cnt_len;
    char    *name;
    char    *ptr;

    counter_s = num_to_str(counter);
    tty_len = ft_strlen(tty_name);
    cnt_len = ft_strlen(counter_s);
    name = new_allocation(EXECUTION ,tty_len + cnt_len + 19);
    ptr = name;
    ft_memcpy(ptr, prefix, 9);
    ptr += 9;
    ft_memcpy(ptr, tty_name, tty_len);
    ptr += tty_len;
    *ptr++ = '_';
    ft_memcpy(ptr, counter_s, cnt_len);
    ptr += cnt_len;
    ft_memcpy(ptr, sufix, 8);
    ptr += 8;
    *ptr = '\0';
    return (name);
}

static int	heredoc_write_read(char *tty_name, int *wfd, int *rfd)
{
    static unsigned int counter = INT_MAX;
	char			    *heredoc_name;
	int				    tries;

	tries = 0;
	while (tries++ < 1000)
	{
		heredoc_name = compose_name(tty_name, "/tmp/nsh_", ".heredoc", counter--);
        // printf("%s\n", heredoc_name);
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

static int nothing(void) { return 0; }

static void heredoc_sigint(int signal)
{
    (void)signal;
    _exit_status(UPDATE, 130);
    heredoc_exit = 130;
    rl_done = 1;
}

static void heredoc_signals(void)
{
    rl_event_hook = nothing;
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, heredoc_sigint);
}

static bool write_heredoc(int wfd, char *delimiter)
{
    size_t  d_len;
    char    *line;

    d_len = ft_strlen(delimiter);
    while (heredoc_exit == 0)
    {
        line = readline("> ");
        if (!line)
            break;
        if (ft_strlen(line) == d_len && !ft_strcmp(line, delimiter))
        {
            free(line);
            break;
        }
        if (*line)
            write(wfd, line, ft_strlen(line));
        write(wfd, "\n", 1);
        free(line);
    }
    if (heredoc_exit == 130)
        return (true);
    return (false);
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
    fail_check = heredoc_write_read(tty_name, &wfd, &rfd);
    if (fail_check)
        return (-1);
    heredoc_signals();
    fail_check = write_heredoc(wfd, delimiter);
    close(wfd);
    shell_signals();
    if (fail_check)
        return (-1);
    return (rfd);
}

static int *heredoc(char *delimiter)
{
    int *pointer;
    int fd;

    fd = open_heredoc(delimiter);
    if (fd < 0)
        return (NULL);
    pointer = new_allocation(EXECUTION, sizeof(int));
    *pointer = fd;
    return (pointer);
}

int check_for_heredoc(t_tree *branch)
{
    t_redir *redirs;
    int     n_redirs;
    int     i;

    i = -1;
    heredoc_exit = 0;
    if (!get_redirs(branch, &redirs, &n_redirs))
        return (heredoc_exit);
    while(++i < n_redirs && !heredoc_exit)
        if (redirs[i].type == OP_HEREDOC)
            redirs[i].file = heredoc(redirs[i].file);
    return (heredoc_exit);
}