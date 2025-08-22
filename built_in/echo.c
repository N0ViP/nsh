/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:20 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:09 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	built_in_echo(t_cmd *cmd_args)
{
	char	*args;
	char	**argv;
	bool	new_line;

	argv = cmd_args->args;
	new_line = true;
	argv++;
	if (*argv && !ft_strcmp(*argv, "-n"))
	{
		argv++;
		new_line = false;
	}
	args = ft_strjoin(argv, " ");
	if (new_line)
	{
		args = join_two_strings(args, "\n", "");
	}
	write(1, args, ft_strlen(args));
	return (EXIT_SUCCESS);
}
