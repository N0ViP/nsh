/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:35:11 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:35:12 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	join_list(t_list_info *lst_1, t_list_info *lst_2)
{
	if (!lst_2->list)
	{
		return ;
	}
	if (!lst_1->list)
	{
		lst_1->list = lst_2->list;
	}
	else
	{
		lst_1->tail->next = lst_2->list;
	}
	lst_1->tail = lst_2->tail;
	lst_1->size += lst_2->size;
}
