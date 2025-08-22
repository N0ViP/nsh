/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:33:17 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:33:18 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

void	exit_shell(int exit_status)
{
	close_everything();
	destroy_everything();
	exit(exit_status);
}
