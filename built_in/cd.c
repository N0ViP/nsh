/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:17 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:05 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	print_cd_error(char *path, char *error)
{
	write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
	write(STDERR_FILENO, ": cd: ", 6);
	if (path)
	{
		write(STDERR_FILENO, path, ft_strlen(path));
		write(STDERR_FILENO, ": ", 2);
	}
	if (error)
	{
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", 1);
	}
}

int	built_in_cd(t_cmd *cmd_args)
{
	char	**path;

	if (cmd_args->n_arg > 2)
	{
		print_cd_error(NULL, "too many arguments");
		return (EXIT_FAILURE);
	}
	path = cmd_args->args + 1;
	if (!(*path))
	{
		if (!go_home())
			return (EXIT_FAILURE);
	}
	else if (!ft_strcmp(*path, "-"))
	{
		if (!go_old_pwd())
			return (EXIT_FAILURE);
	}
	else
	{
		if (!go_to_path(*path))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
