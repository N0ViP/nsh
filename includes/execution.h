#ifndef EXECUTION_H
# define EXECUTION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"
# include "errno.h"
# include <sys/stat.h>
# include <sys/wait.h>

typedef enum
{
    VALID_PATH,
    STAT_ERROR,
    IS_DIR_ERROR,
    NO_FILE_ERROR,
    NOT_FOUND_ERROR,
    PERMISSION_ERROR,
}   t_state;

typedef enum
{
    DEFAULT_MODE,
    NO_FORK_MODE  
}   t_mode;

int         fork_before(void (*keep_exec)(t_tree *, char **), t_tree *branch, char **envp);
int		    execute_pipeline(t_tree *branch, char **envp, t_mode mode);
int		    execute_subshell(t_tree *branch, char **envp, t_mode mode);
int		    execute_command(t_tree *branch, char **envp, t_mode mode);
int		    execution_mode(t_tree *root, char **envp, t_mode mode);
void        report_error(const char *cmd, t_state error);
int		    execute_or_and(t_tree *branch, char **envp);
int		    execute_tree(t_tree *root, char **envp);
void	    check_redirection(t_tree *branch);
char	    *resolve_path(const char *cmd);
void        exit_failure(char *msg);
t_state     stat_error(void);

#endif