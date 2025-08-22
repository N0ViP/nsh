/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:18 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:59:13 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

static t_section	*recursive_search(t_section **section, t_sid section_id)
{
	t_section	*to_destroy;

	if (!*section)
		return (NULL);
	if ((*section)->section_id == section_id)
	{
		to_destroy = *section;
		*section = to_destroy->next;
		return (to_destroy);
	}
	return (recursive_search(&(*section)->next, section_id));
}

void	destroy_section(t_sid section_id)
{
	t_section	*section;

	section = recursive_search(get_sections(), section_id);
	clear_section_data(section);
}
