/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:38:00 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:38:02 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_node_back(t_list **list, t_list *node)
{
	if (!*list)
	{
		*list = node;
		(*list)->tail = node;
		return ;
	}
	(*list)->tail->next = node;
	(*list)->tail = node;
}
