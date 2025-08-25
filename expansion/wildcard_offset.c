/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_offset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:24 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:04:02 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

size_t	wildcard_offset(int flag)
{
	static size_t	offset;

	if (flag == NEXT_OFFSET)
	{
		offset++;
	}
	else if (flag == PREV_OFFSET && offset)
	{
		offset--;
	}
	else if (flag == RESET_OFFSET)
	{
		offset = 0;
	}
	return (offset);
}
