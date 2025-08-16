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

static char *compose_name(char *prefix, char *tty_name, size_t counter, char *sufix)
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

static int nothing(void)
{
    return 0;
}

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

static void copy_new_delemiter(char **delimiter, size_t new_len)
{
    char    *new_dlm;
    char    *dlm;

    new_dlm = new_allocation(PARSING, new_len + 1);
    dlm = *delimiter;
    *delimiter = new_dlm;
    while (*dlm)
    {
        if (*dlm != '"' && *dlm != '\'')
            *new_dlm++ = *dlm;
        dlm++;
    }
    *new_dlm = '\0';
}

static bool look_for_quotes(char **delimiter)
{
    bool    was_quoted;
    size_t  new_len;
    char    *dlm;


    new_len = 0;
    dlm = *delimiter;
    was_quoted = false;
    while (*dlm)
    {
        if (!was_quoted && (*dlm == '"' || *dlm == '\''))
        {
            was_quoted = true;
        }
        else if (!(*dlm == '"' || *dlm == '\''))
        {
            new_len++;
        }
        dlm++;
    }
    copy_new_delemiter(delimiter, new_len);
    return (was_quoted);
}

static size_t compute_total(t_list  *node)
{
    size_t  total;
    size_t  count;

    total = 0;
    count = 0;
    while (node)
    {
        if (node->content)
            total += ft_strlen((char *)node->content);
        count++;
        node = node->next;
    }
    if (count > 1)
        total += (count - 1);
    return (total);
}

static void joine_string(t_list  *node, char *to_fill, size_t total)
{
    char    *content;
    size_t  len;

    while (node)
    {
        content = (char *)node->content;
        if (content)
        {
            len = ft_strlen(content);
            if (len > 0)
            {
                ft_memcpy(to_fill, content, len);
                to_fill += len;
                total -= len;
            }
        }
        if (node->next && total)
        {
            *to_fill = ' ';
            to_fill++;
            total--;
        }
        node = node->next;
    }
    *to_fill = '\0';
}

char    *join_list_strings(t_list_info *info)
{
    t_list              *node;
    size_t              total;
    char                *joined_strings;

    if (!info || !info->list)
        return (allocate_retval(PARSING, ""));

    node = info->list;

    total = compute_total(node);

    joined_strings = new_allocation(PARSING, total + 1);
    joine_string(node, joined_strings, total);
    return (joined_strings);
}

static bool is_delimiter(char *line, char *delimiter)
{
    if (!line)
        return (true);
    if (ft_strlen(line) == ft_strlen(delimiter)
        && !ft_strcmp(line, delimiter))
    {
        free(line);
        return (true);
    }
    return (false);
}

static void write_expanded_line(int wfd, char *line)
{
    t_list_info *list;
    char        *expanded;

    list = expander(line);
    expanded = join_list_strings(list);
    if (expanded && *expanded)
    {
        write(wfd, expanded, ft_strlen(expanded));
    }
}

static bool process_line(int wfd, char *line, bool was_quoted, char *delimiter)
{
    if (is_delimiter(line, delimiter))
        return (true);
    if (was_quoted)
    {
        if (*line)
            write(wfd, line, ft_strlen(line));
    }
    else
    {
        if (*line)
            write_expanded_line(wfd, line);
    }
    write(wfd, "\n", 1);
    return (false);
}

static bool write_to_heredoc(int wfd, char *delimiter)
{
    char    *line;
    bool    was_quoted;

    was_quoted = look_for_quotes(&delimiter);
    while (heredoc_exit == 0)
    {
        line = readline("> ");// history
        if (process_line(wfd, line, was_quoted, delimiter))
            break;
        free(line);
    }
    return (heredoc_exit == 130);
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

static int process_heredocs(t_tree *branch)
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

bool look_for_heredocs(t_tree *root)
{
	if (!root)
		return (true);
	if (root->type == COMMAND)
	{
		if (process_heredocs(root) == 130)
			return (false);
		return (true);
	}
	else if (root->type == SUBSHELL)
	{
		if (process_heredocs(root) == 130)
			return (false);
		if (!look_for_heredocs(root->data.subshell.child))
			return (false);
		return (true);
	}
	if (!look_for_heredocs(root->data.branch.left))
		return (false);
	if (!look_for_heredocs(root->data.branch.right))
		return (false);
    return (true);
}