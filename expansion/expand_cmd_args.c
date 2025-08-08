#include "expansion.h"

char	**expand_cmd_args(t_cmd *cmd)
{
	char		**res;
	size_t		i;
	t_list_info	*args_list;
	t_list_info	*arg_list;

	i = 0;
	args_list = init_list_info_struct();
	while (cmd->args[i])
	{
		arg_list = expander(cmd->args[i]);
		join_list(args_list, arg_list);
		i++;
	}
	res = lst_to_arr(args_list);
	return (res);
}
