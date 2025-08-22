/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:37:28 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/22 07:01:56 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

int	main(void)
{
	char	*command;

	while (init())
	{
		if (read_command(&command))
		{
			new_shell(command);
		}
	}
	return (EXIT_SUCCESS);
}
