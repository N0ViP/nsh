#ifndef EXECUTION_H
# define EXECUTION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"
# include "errno.h"
# include <limits.h>//
# include <sys/stat.h>
# include <sys/wait.h>

# define UPDATE 0
# define EXTRACT 1

extern int heredoc_exit;

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


t_state     stat_error(void);
void        exit_failure(char *msg);
void		execute_tree(t_tree *root);
char	    *path_resolution(char *cmd);
char        *check_and_curr_dir(char *cmd);
int		    execute_or_and(t_tree *branch);
t_state     path_validity(const char *path);
bool        built_ins_check(t_tree *branch);
void	    redirection_setup(t_tree *branch);
int 	    _exit_status(bool flag, int value);
int		    execution_mode(t_tree *root, t_mode mode);
void        report_error(const char *cmd, t_state error);
int		    execute_command(t_tree *branch, t_mode mode);
int		    execute_subshell(t_tree *branch, t_mode mode);
int		    execute_pipeline(t_tree *branch, t_mode mode);
pid_t       fork_left_pipe(int pipefd[2], t_tree *branch);
pid_t       fork_right_pipe(int pipefd[2], t_tree *branch);
int         fork_before(void (*keep_exec)(t_tree *), t_tree *branch);
char        *search_in_paths(char *cmd, char **paths, t_state *state);
bool        get_redirs(t_tree *branch, t_redir **redirs, int *n_redirs);

#endif