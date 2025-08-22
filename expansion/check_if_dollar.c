/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:56 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:21:57 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

bool	check_if_dollar(char *str)
{
	if (str[0] != '$' || (!ft_isalpha(str[1]) && str[1] != '_'
			&& str[1] != '?'))
	{
		return (false);
	}
	return (true);
}
