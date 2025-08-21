# include "execution.h"

int execute_or_and(t_tree *branch)
{
    t_tree  *sub_branch[2];
    int     left_status;

    sub_branch[0] = branch->data.branch.left;
    sub_branch[1] = branch->data.branch.right;
    left_status = execution_mode(sub_branch[0], DEFAULT_MODE);
    if (g_signaled == SIGINT && left_status == 130)
        return (left_status);
    if ((branch->type == OP_AND && left_status == 0) ||
        (branch->type == OP_OR  && left_status != 0))
        return (execution_mode(sub_branch[1], DEFAULT_MODE));
    return (left_status);
}
