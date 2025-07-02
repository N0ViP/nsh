/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:38:43 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:38:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_list(t_list_info **list_info, void (*free_content)())
{
	t_list	*node;

	while ((*list_info)->list)
	{
		node = (*list_info)->list;
		(*list_info)->list = (*list_info)->list->next;
		free_content(node);
		free(node);
	}
	free(*list_info);
	*list_info = NULL;
}
