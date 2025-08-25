/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:16 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:02:35 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	init_info_struct(t_info *info, char *str)
{
	info->len = 0;
	info->str = str;
	info->hashmap = add_in_wildcard_hashmap(0, RESET_OFFSET, false);
	info->ex_word = init_list_info_struct();
}
