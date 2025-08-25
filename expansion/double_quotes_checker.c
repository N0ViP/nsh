/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:58 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:00:57 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

bool	double_quotes_checker(char *str)
{
	if (*str != '\0' && *str != '"' && !check_if_dollar(str))
	{
		return (true);
	}
	return (false);
}
