/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:02 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:21:02 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	exit_failure(char *msg)
{
	write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
	write(STDERR_FILENO, ": ", 2);
	perror(msg);
	exit_shell(EXIT_FAILURE);
}

bool	return_failure(char *msg)
{
	write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
	write(STDERR_FILENO, ": ", 2);
	perror(msg);
	return (false);
}
