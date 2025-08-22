/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:12 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:22:13 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	utils(t_info *info, size_t i, size_t j, bool ex_wdc)
{
	t_list	*node;
	char	*word;

	add_in_wildcard_hashmap(info->wildcard, CURR_OFFSET, ex_wdc);
	word = ft_substr(info->str, i, j);
	node = creat_node(word);
	list_add_back(info->ex_word, node);
	info->len += j - i;
}
