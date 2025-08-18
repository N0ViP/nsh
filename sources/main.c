/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:37:28 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/17 17:44:42 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

int	main(void)
{
	char	*command;

	while (init())
	{
		if(read_command(&command))
		{
			new_shell(command);
			// print_all_sections();
		}
	}
	return(EXIT_SUCCESS);
}