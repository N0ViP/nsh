# include "execution.h"

int execution_mode(t_tree *root, char **envp, t_mode mode)
{
    if (!root)
        return (0);
    else if (root->type == COMMAND)
        return (_exit_status(SAVE_VALUE, execute_command(root, envp, mode)));
    else if (root->type == SUBSHELL)
        return (_exit_status(SAVE_VALUE, execute_subshell(root, envp, mode)));
    else if (root->type == OP_PIPE)
        return (_exit_status(SAVE_VALUE, execute_pipeline(root, envp, mode)));
    else if (root->type == OP_OR || root->type == OP_AND)
        return (_exit_status(SAVE_VALUE, execute_or_and(root, envp)));
    return (1);
}

int execute_tree(t_tree *root, char **envp)
{
    return (execution_mode(root, envp, DEFAULT_MODE));
}
