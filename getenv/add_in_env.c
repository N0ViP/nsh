/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:23:41 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 00:44:09 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getenv.h"

static bool	check_modify_key(t_list *ptr, char *var)
{
	int	reval;

	reval = ft_strcmp_env(ptr->content, var);
	if (reval == 0)
	{
		return (true);
	}
	if (reval == 1)
	{
		free_one_pointer(REMAINS, ptr->content);
		ptr->content = var;
		return (true);
	}
	return (false);
}

void	add_in_env(t_list_info *env, char *var)
{
	t_list	*ptr;
	t_list	*node;

	ptr = env->list;
	while (ptr)
	{
		if (check_modify_key(ptr, var))
		{
			return ;
		}
		ptr = ptr->next;
	}
	set_current_section(REMAINS);
	node = creat_node(var);
	set_current_section(GLOBALE);
	list_add_back(env, node);
}
