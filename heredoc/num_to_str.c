/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:51 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:24:52 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

char	*num_to_str(unsigned long v)
{
	unsigned long	tmp;
	int				digits;
	char			*s;

	tmp = v;
	digits = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	s = allocate_memory(digits + 1);
	s[digits] = '\0';
	while (digits > 0)
	{
		digits--;
		s[digits] = '0' + (v % 10);
		v /= 10;
	}
	return (s);
}
