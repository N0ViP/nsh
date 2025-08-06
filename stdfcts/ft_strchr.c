/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:48:40 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/06 01:49:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (true);
		i++;
	}
	return (false);
}
