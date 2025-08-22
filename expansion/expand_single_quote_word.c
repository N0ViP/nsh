/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_quote_word.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:07 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:22:08 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

size_t	expand_single_quote_word(t_info *info)
{
	size_t	n;

	n = 1;
	info->wildcard = 0;
	if (info->str[0] != '\'')
	{
		return (0);
	}
	while (info->str[n] != '\'')
	{
		if (info->str[n] == '*')
		{
			info->wildcard++;
		}
		n++;
	}
	if (n >= 1)
	{
		utils(info, 1, n, false);
	}
	return (n + 1);
}
