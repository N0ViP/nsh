# include "execution.h"

int execution_mode(t_tree *root, t_mode mode)
{
    if (root->type == COMMAND)
        return (_exit_status(SAVE_VALUE, execute_command(root, mode)));
    else if (root->type == SUBSHELL)
        return (_exit_status(SAVE_VALUE, execute_subshell(root, mode)));
    else if (root->type == OP_PIPE)
        return (_exit_status(SAVE_VALUE, execute_pipeline(root, mode)));
    else if (root->type == OP_OR || root->type == OP_AND)
        return (_exit_status(SAVE_VALUE, execute_or_and(root)));//should i use made in here too
    return (EXIT_FAILURE);
}

void execute_tree(t_tree *root)
{
    execution_mode(root, DEFAULT_MODE);
    destroy_section(PARSING);
}
