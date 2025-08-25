/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:46 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:08:22 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	built_in_unset(t_cmd *cmd_args)
{
	char	**args;
	size_t	i;

	i = 1;
	args = cmd_args->args;
	while (args[i])
	{
		ft_getenv(REMOVE_FROM_ENV, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
