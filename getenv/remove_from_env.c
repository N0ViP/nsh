/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:28 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 01:43:25 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getenv.h"

static void	free_var_node(t_list *node)
{
	free_one_pointer(REMAINS, node->content);
	free_one_pointer(REMAINS, node);
}

static bool	check_and_remove(t_list *ptr, char *var)
{
	t_list		*tmp;
	t_list_info	*env;

	if (!ft_strcmp_env(ptr->next->content, var))
	{
		tmp = ptr->next;
		ptr->next = ptr->next->next;
		env = *env_list();
		env->tail = ptr;
		free_var_node(tmp);
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
		free_var_node(ptr);
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
