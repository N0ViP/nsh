/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_list_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:43 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:24:44 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static size_t	compute_total(t_list *node)
{
	size_t	total;
	size_t	count;

	total = 0;
	count = 0;
	while (node)
	{
		if (node->content)
			total += ft_strlen((char *)node->content);
		count++;
		node = node->next;
	}
	if (count > 1)
		total += (count - 1);
	return (total);
}

char	*join_list_strings(t_list_info *info)
{
	t_list	*node;
	size_t	total;
	char	*joined_content;

	if (!info || !info->list)
		return (ft_strdup(""));
	node = info->list;
	total = compute_total(node);
	joined_content = join_list_content(node, " ", total);
	return (joined_content);
}
