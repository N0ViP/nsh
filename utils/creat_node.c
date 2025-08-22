/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:56 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:59 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*creat_node(void *content)
{
	t_list	*node;

	node = allocate_memory(sizeof(t_list));
	node->content = content;
	node->next = NULL;
	return (node);
}
