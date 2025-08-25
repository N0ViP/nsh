/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_word_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:22:21 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:03:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

bool	regular_word_checker(char *str)
{
	if (*str != '\0' && *str != '\'' && *str != '"' && !check_if_dollar(str))
	{
		return (true);
	}
	return (false);
}
