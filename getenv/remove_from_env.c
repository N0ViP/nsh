/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:28 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 03:40:47 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getenv.h"

static void	free_var_node(t_list *node, t_list *new_tail)
{
	t_list_info	*env;
	
	env = *env_list();
	if (env->tail == node)
	{
		env->tail = new_tail;
	}
	free_one_pointer(REMAINS, node->content);
	free_one_pointer(REMAINS, node);
}

static bool	check_and_remove(t_list *ptr, char *var)
{
	t_list		*tmp;

	if (!ft_strcmp_env(ptr->next->content, var))
	{
		tmp = ptr->next;
		ptr->next = ptr->next->next;
		free_var_node(tmp, ptr);
		return (true);
	}
	return (false);
}

void	remove_from_env(t_list_info *env, char *var)
{
	t_list	*ptr;

	ptr = env->list;
	if (!ptr)
	{
		return ;
	}
	if (!ft_strcmp_env(ptr->content, var))
	{
		env->list = env->list->next;
		free_var_node(ptr, NULL);
		env->size--;
		return ;
	}
	while (ptr->next)
	{
		if (check_and_remove(ptr, var))
		{
			env->size--;
			return ;
		}
		ptr = ptr->next;
	}
}
