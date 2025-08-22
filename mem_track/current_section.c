/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:11 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:59:00 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

t_sid	*current_section(void)
{
	static t_sid	current_section_id = TOKENIZE;

	return (&current_section_id);
}

void	set_current_section(t_sid updated_section_id)
{
	t_sid	*current_section_id;

	current_section_id = current_section();
	*current_section_id = updated_section_id;
}
