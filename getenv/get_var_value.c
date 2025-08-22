/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:23:46 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:23:47 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getenv.h"

static char	*split_val_from_key(char *var)
{
	char	*value;
	size_t	i;

	i = 0;
	while (var[i] != '\0' && var[i] != '=')
	{
		i++;
	}
	if (var[i] == '\0' || var[i + 1] == '\0')
	{
		return (NULL);
	}
	value = ft_substr(var, i + 1, ft_strlen(var));
	return (value);
}

char	*get_var_value(char *var)
{
	t_list_info	*env;
	t_list		*ptr;
	char		*value;

	env = *env_list();
	ptr = env->list;
	while (ptr)
	{
		if (!ft_strcmp_env(ptr->content, var))
		{
			value = split_val_from_key(ptr->content);
			return (value);
		}
		ptr = ptr->next;
	}
	return (NULL);
}
