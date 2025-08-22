/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:08 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:21:09 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	_exit_status(bool flag, int value)
{
	static int	exit_status;

	if (flag == UPDATE)
	{
		exit_status = value;
	}
	return (exit_status);
}
