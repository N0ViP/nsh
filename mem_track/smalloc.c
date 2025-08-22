/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:34 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:35 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

void	*smalloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
	{
		exit_failure("malloc");
	}
	return (pointer);
}
