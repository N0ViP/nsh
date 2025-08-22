/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_wildcard_hashmap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:53 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:21:54 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static bool	**wildcard_hashmap(void)
{
	static bool	*hashmap = NULL;

	return (&hashmap);
}

void	init_hashmap(void)
{
	bool	**hashmap;

	hashmap = wildcard_hashmap();
	*hashmap = new_allocation(REMAINS, INITIAL_CAPACITY * sizeof(bool));
}

bool	*add_in_wildcard_hashmap(size_t wildcard, int flag, bool ex_wdc)
{
	static size_t	cap = INITIAL_CAPACITY;
	static size_t	i = 0;
	bool			*hashmap;

	hashmap = *wildcard_hashmap();
	if (flag == RESET_OFFSET)
	{
		i = 0;
	}
	if (cap < i + wildcard)
	{
		while (cap < i + wildcard)
		{
			cap *= 2;
		}
		hashmap = ft_realloc(hashmap, i * sizeof(bool), cap * sizeof(bool));
	}
	while (wildcard--)
	{
		hashmap[i++] = ex_wdc;
	}
	return (hashmap);
}
