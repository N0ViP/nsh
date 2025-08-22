/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:33:24 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:33:25 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

bool	init(void)
{
	static bool	init = false;

	g_signaled = 0;
	if (init == false)
	{
		init_hashmap();
		update_cwd();
		env_setup();
		init_fds();
		init = true;
	}
	return (init);
}

void	new_shell(char *cmd)
{
	t_list	*tokens;

	tokens = tokenize(cmd);
	if (!tokens)
	{
		return (clean_before_prompt());
	}
	else if (!parse_check(tokens))
	{
		_exit_status(UPDATE, 2);
		return (clean_before_prompt());
	}
	else
	{
		execute_tree(parse_in_tree(tokens));
		return (clean_before_prompt());
	}
}
