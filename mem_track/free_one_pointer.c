/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_one_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:29 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:30 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

void	free_one_pointer(t_sid section_id, void *pointer)
{
	t_section	*section;
	void		**allocs;
	size_t		cnt;

	section = find_section(*get_sections(), section_id);
	if (!section)
		return ;
	allocs = section->allocations;
	cnt = section->count;
	while (cnt--)
	{
		if (allocs[cnt] == pointer)
		{
			free(pointer);
			(section->count)--;
			allocs[cnt] = allocs[section->count];
			return ;
		}
	}
}
