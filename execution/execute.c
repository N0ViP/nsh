# include "nsh.h"

void exit_failure(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

static void redirect(const char *file, int flags, int target_fd)
{
    int fd;
    
    fd = open(file, flags, 0644);
    if (fd < 0)
        exit_failure((char *)file);
    if (dup2(fd, target_fd) < 0)
        exit_failure("dup2");
    close(fd);
}
static void heredoc(const char *delimiter)
{
    (void)delimiter;
}

static void setup_redirection(t_redir *redir, int n_redirs)
{
    int i;

    i = 0;
    while(i < n_redirs)
    {
        if (redir[i].type == OP_REDIR_IN)
            redirect(redir[i].file, O_RDONLY, STDIN_FILENO);
        else if (redir[i].type == OP_REDIR_OUT)
            redirect(redir[i].file,
                        O_WRONLY | O_CREAT | O_TRUNC, 
                        STDOUT_FILENO);
        else if (redir[i].type == OP_APPEND)
            redirect(redir[i].file,
                        O_WRONLY | O_CREAT | O_APPEND,
                        STDOUT_FILENO);
        else if (redir[i].type == OP_HEREDOC)
            heredoc(redir[i].file);
        i++;
    }
}

static void check_redirection(t_tree *branch)
{
    t_redir *redir;
    int     n_redirs;

    redir = NULL;
    n_redirs = 0;
    if(branch->type == COMMAND)
    {
        redir = branch->data.cmd.redirs;
        n_redirs = branch->data.cmd.n_redirs;
    }
    else if(branch->type == SUBSHELL)
    {
        redir = branch->data.subshell.redirs;
        n_redirs = branch->data.subshell.n_redirs;
    }
    if(!n_redirs)
        return ;
    setup_redirection(redir, n_redirs);
}

void    _free(char **str)
{
	char	**first;

	first = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(first);
}

static void report_error(const char *cmd, t_state error)
{
    int code;

    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, ft_strlen(cmd));

    if (error == NOT_FOUND_ERROR)
        write(STDERR_FILENO, ": command not found\n", 20);
    else if (error == NO_FILE_ERROR)
        write(STDERR_FILENO, ": No such file or directory\n", 28);
    else if (error == IS_DIR_ERROR)
        write(STDERR_FILENO, ": Is a directory\n", 17);
    else if (error == PERMITION_ERROR)
        write(STDERR_FILENO, ": Permission denied\n", 20), free((void *)cmd);

    if(error == NOT_FOUND_ERROR || error == NO_FILE_ERROR)
        code = 127;
    else
        code = 126;
    exit(code);
}

static t_state path_validity(const char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) < 0)
		return (NO_FILE_ERROR);
	if (S_ISDIR(st.st_mode))
		return (IS_DIR_ERROR);
	if (access(cmd, X_OK) < 0)
		return (PERMITION_ERROR);
	return (VALID_PATH);
}

static char	*find_in_path(const char *cmd, char **paths)
{
	char		*full_path;
	char		*last_path;
	char		*slash;
	t_state		state;
	t_state		error;
	int			i;

	i = 0;
    slash = NULL;
    full_path = NULL;
    last_path = NULL;
    error = NOT_FOUND_ERROR;
	while (paths[i])
	{
		slash = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(slash, cmd);
		free(slash);
        state = path_validity(full_path);
        if(state == VALID_PATH)
            return (_free(paths), full_path);
        else if(state == IS_DIR_ERROR || state == PERMITION_ERROR)
        {
            error = state;
            if(state == PERMITION_ERROR)
            {
                free(last_path);
                last_path = ft_strndup(full_path, ft_strlen(full_path)); 
            }
        }
		free(full_path);
		full_path = NULL;
		i++;
	}
    if(error == PERMITION_ERROR)
	    report_error(last_path, error);
    free(last_path);
    report_error(cmd, error);
	return (NULL);
}

static char	*resolve_path(const char *cmd)
{
    t_state		state;
    char		**paths;

	if (ft_strchr(cmd, '/'))
    {
        state = path_validity(cmd);
        if(state == VALID_PATH)
            return (ft_strndup(cmd, ft_strlen(cmd)));
        else
            return (report_error(cmd, state), NULL);
    }
    paths = ft_split(getenv("PATH"), ':');
    return (find_in_path(cmd, paths));
}

static void execute(t_tree *b, char **envp)
{
    char    *path;
    char   **argv;

    check_redirection(b);
    argv = b->data.cmd.args;
    path = resolve_path(argv[0]);
    execve(path, argv, envp);
    // if (errno == ENOEXEC)
    // {
    //     int count = b->data.cmd.n_arg;
    //     char *sh_argv[count + 2];
    //     int  i = 0;
    //     sh_argv[i++] = strdup("sh");
    //     sh_argv[i++] = strdup(path);
    //     while (argv[i - 1] != NULL && i < count + 1)
    //         sh_argv[i] = argv[i - 1], ++i;
    //     sh_argv[i] = NULL;
    //     execve("/bin/sh", sh_argv, envp);
    // }
    perror(SHELL);
    exit(EXIT_FAILURE);
}

static int execute_command(t_tree *branch, char **envp)
{
    int status;
    pid_t pid;

    status = 0;
    pid = fork();
    if (pid < 0)
        exit_failure("fork");
    if (pid == 0)
        execute(branch, envp);
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}

int execute_subshell(t_tree *branch, char **envp)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
        exit_failure("fork");
    if (pid == 0)
    {
        check_redirection(branch);
        status = execute_tree(branch->data.subshell.child, envp);
        exit(status);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}

int execute_or_and(t_tree *branch, char **envp)
{
    int left_status;

    left_status = execute_tree(branch->data.branch.left, envp);
    if ((branch->type == OP_AND && left_status == 0) ||
        (branch->type == OP_OR  && left_status != 0))
        return execute_tree(branch->data.branch.right, envp);
    return left_status;
}

int execute_pipeline(t_tree *branch, char **envp)
{
    int pipefd[2];
    pid_t left, right;
    int status;

    if (pipe(pipefd) < 0)
        exit_failure("pipe");
    left = fork();
    if (left < 0) 
        exit_failure("fork");
    if (left == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        exit(execute_tree(branch->data.branch.left, envp));
    }
    right = fork();
    if (right < 0) 
        exit_failure("fork");
    if (right == 0)
    {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        exit(execute_tree(branch->data.branch.right, envp));
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(left, NULL, 0);
    waitpid(right, &status, 0);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (1);
}


int execute_tree(t_tree *root, char **envp)
{
    if (!root)
        return (0);
    else if (root->type == COMMAND)
        return (execute_command(root, envp));
    else if (root->type == SUBSHELL)
        return (execute_subshell(root, envp));
    else if (root->type == OP_PIPE)
        return (execute_pipeline(root, envp));
    else if (root->type == OP_OR || root->type == OP_AND)
        return (execute_or_and(root, envp));
    return (1);
}
