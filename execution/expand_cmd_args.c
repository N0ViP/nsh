#include "execution.h"

bool expand_cmd_args(t_tree *branch)
{
	t_list_info		*args_list;
	t_list_info		*arg_list;
	char			**args;
	size_t			i;

	i = 0;
	if (!branch->data.cmd.n_arg)
		return (_exit_status(UPDATE, EXIT_SUCCESS), false);
	args = branch->data.cmd.args;
	args_list = init_list_info_struct();
	while (args[i])
	{
		arg_list = expander(args[i]);
		join_list(args_list, arg_list);
		i++;
	}
	branch->data.cmd.n_arg = args_list->size;
	branch->data.cmd.args = lst_to_arr(args_list);
	if (!branch->data.cmd.n_arg)
		return (_exit_status(UPDATE, EXIT_SUCCESS), false);
	return (true);
}
