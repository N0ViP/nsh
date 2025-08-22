/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_before_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:02 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:03 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_track.h"

static t_section	*recurse_skip_env(t_section *section)
{
	t_section	*env_section;

	if (!section)
		return (NULL);
	env_section = recurse_skip_env(section->next);
	if (section->section_id == REMAINS)
		return (section->next = NULL, section);
	clear_section_data(section);
	return (env_section);
}

void	clean_before_prompt(void)
{
	t_section	**sections;

	sections = get_sections();
	*sections = recurse_skip_env(*sections);
	return (close_everything());
}
