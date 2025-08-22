/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:10 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:11 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdfcts.h"

char	*ft_itoa(int n)
{
	char	*res;
	size_t	num_len;
	bool	is_negative;

	is_negative = (n < 0);
	num_len = ft_numlen(n) + (size_t)is_negative;
	res = allocate_memory(num_len + 1);
	res[num_len--] = '\0';
	if (n == 0)
	{
		res[num_len] = '0';
	}
	while (n)
	{
		res[num_len--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
	{
		res[num_len--] = '-';
	}
	return (res);
}
