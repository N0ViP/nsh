# include "heredoc.h"

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
