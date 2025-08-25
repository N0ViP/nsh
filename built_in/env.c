/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:22 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 05:25:28 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	print_env(t_list *env_list)
{
	char	*equal;
	int		reval;

	reval = 0;
	while (env_list)
	{
		equal = ft_strchr(env_list->content, '=');
		if (equal)
		{
			reval = printf("%s\n", (char *)env_list->content);
		}
		if (reval == -1)
		{
			perror("env: write error");
			return (125);
		}
		env_list = env_list->next;
	}
	return (0);
}

int	built_in_env(t_cmd *cmd_args)
{
	t_list_info	*env;
	int			exit_status;

	(void)cmd_args;
	env = *env_list();
	exit_status = print_env(env->list);
	return (exit_status);
}
