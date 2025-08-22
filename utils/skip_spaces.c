/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:39:36 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/22 05:35:29 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	skip_spaces(char *str, size_t i)
{
	size_t	j;

	j = 0;
	while (ft_isspace(str[i + j]))
	{
		j++;
	}
	return (j);
}
