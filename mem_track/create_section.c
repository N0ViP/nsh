/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_section.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:09 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:10 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

t_section	**get_sections(void)
{
	static t_section	*pointer_to_sections = NULL;

	return (&pointer_to_sections);
}

t_section	*create_section(t_sid section_id)
{
	t_section	*section;

	section = smalloc(sizeof(t_section));
	section->section_id = section_id;
	section->allocations = smalloc(sizeof(void *) * INITIAL_CAPACITY);
	section->count = 0;
	section->capacity = INITIAL_CAPACITY;
	section->next = *get_sections();
	*get_sections() = section;
	return (section);
}
