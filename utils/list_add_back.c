/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:38:00 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/23 01:38:28 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	list_add_back(t_list_info *list_info, t_list *node)
{
	if (!list_info->size)
	{
		list_info->list = node;
	}
	else
	{
		list_info->tail->next = node;
	}
	list_info->tail = node;
	list_info->size++;
}
