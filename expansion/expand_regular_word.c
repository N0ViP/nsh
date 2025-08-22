/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_regular_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:05 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:22:06 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

size_t	expand_regular_word(t_info *info, bool (*checker)(char *), bool ex_wdc)
{
	size_t	n;

	n = 0;
	info->wildcard = 0;
	while (checker(info->str + n))
	{
		if (info->str[n] == '*')
		{
			info->wildcard++;
		}
		n++;
	}
	if (n > 0)
	{
		utils(info, 0, n, ex_wdc);
	}
	return (n);
}
