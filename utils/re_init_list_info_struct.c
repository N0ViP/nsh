/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_init_list_info_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:35:25 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 07:05:12 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	re_init_list_info_struct(t_list_info *list_info)
{
	list_info->list = NULL;
	list_info->tail = NULL;
	list_info->size = 0;
}
