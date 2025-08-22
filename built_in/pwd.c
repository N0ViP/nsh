/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:39 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:27 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	built_in_pwd(t_cmd *cmd_args)
{
	char	*cwd;

	(void)cmd_args;
	cwd = *shell_cwd();
	if (!cwd)
		return (EXIT_FAILURE);
	write(STDERR_FILENO, cwd, ft_strlen(cwd));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
