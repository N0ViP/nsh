/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wildcard_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:14 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:02:29 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

bool	get_wildcard_flag(t_info *info)
{
	static size_t	i;

	return ((bool)info->hashmap[i++]);
}
