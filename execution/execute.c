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

char	*find_path(char *cmd)
{
	int		i;
	char	**paths;
	char	*cmd_path;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		cmd_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	_free(paths);
	return (NULL);
}

static void not_found(char *str, char flag)
{
    write(STDERR_FILENO, "nsh: ", 5);
    if(flag)
    {
        write(STDERR_FILENO, str, ft_strlen(str));
        write(STDERR_FILENO, ": command not found", 19);
        write(STDERR_FILENO, "\n", 1);
    }
    else
        perror(str);
    exit(127);
}

static void execute(t_tree *branch, char **envp)
{
    char *exec_path;
    char **argv;
    
    check_redirection(branch);
    exec_path = NULL;
    argv = branch->data.cmd.args;
    if (ft_strchr(argv[0], '/'))
    {
		if (access(argv[0], F_OK | X_OK) == 0)
			exec_path = ft_strndup(argv[0], ft_strlen(argv[0]));
        else
            not_found(argv[0], 0);
    }
    else
    {
        exec_path = find_path(argv[0]);
        if (!exec_path)
            not_found(argv[0], 1);
    }
    execve(exec_path, argv, envp);
    exit_failure("execvp");
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
