/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:04 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:05 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

void	clear_section_data(t_section *section)
{
	size_t	cnt;

	if (!section)
		return ;
	cnt = section->count;
	while (cnt--)
		free(section->allocations[cnt]);
	free(section->allocations);
	free(section);
}
