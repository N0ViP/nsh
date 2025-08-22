/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:23:49 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:23:50 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getenv.h"

t_list_info	**env_list(void)
{
	static t_list_info	*env = NULL;

	return (&env);
}

void	env_setup(void)
{
	t_list_info	**env;

	env = env_list();
	*env = init_env();
}

t_list_info	*ft_getenv(int flag, char *var)
{
	t_list_info	*env;
	char		*dup_var;

	env = *env_list();
	if (var)
	{
		set_current_section(REMAINS);
		dup_var = ft_strdup(var);
		set_current_section(GLOBALE);
	}
	if (flag == ADD_IN_ENV)
	{
		add_in_env(env, dup_var);
	}
	else if (flag == REMOVE_FROM_ENV)
	{
		remove_from_env(env, dup_var);
	}
	return (env);
}
