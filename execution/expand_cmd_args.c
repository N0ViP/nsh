/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:10 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:54:57 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

bool	expand_cmd_args(t_tree *branch)
{
	t_list_info	*args_list;
	t_list_info	*arg_list;
	char		**args;
	size_t		i;

	i = 0;
	if (!branch->u_data.cmd.n_arg)
		return (_exit_status(UPDATE, EXIT_SUCCESS), false);
	args = branch->u_data.cmd.args;
	args_list = init_list_info_struct();
	while (args[i])
	{
		arg_list = expander(args[i]);
		join_list(args_list, arg_list);
		i++;
	}
	branch->u_data.cmd.n_arg = args_list->size;
	branch->u_data.cmd.args = lst_to_arr(args_list);
	if (!branch->u_data.cmd.n_arg)
		return (_exit_status(UPDATE, EXIT_SUCCESS), false);
	return (true);
}
