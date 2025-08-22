/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_info_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:35:05 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:35:06 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list_info	*init_list_info_struct(void)
{
	t_list_info	*token_info;

	token_info = allocate_memory(sizeof(t_list_info));
	token_info->list = NULL;
	token_info->tail = NULL;
	token_info->size = 0;
	return (token_info);
}
