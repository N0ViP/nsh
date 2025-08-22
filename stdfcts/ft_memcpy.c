/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:12 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:13 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdfcts.h"

void	*ft_memcpy(void *d, void *s, size_t len)
{
	void	*dest;

	if (!d || !s)
		return (NULL);
	dest = d;
	while (!((size_t)d % sizeof(size_t)) && len)
	{
		*((char *)d++) = *((char *)s++);
		len--;
	}
	while (len >= sizeof(size_t))
	{
		*((size_t *)d) = *((size_t *)s);
		d += sizeof(size_t);
		s += sizeof(size_t);
		len -= sizeof(size_t);
	}
	while (len)
	{
		*((char *)d++) = *((char *)s++);
		len--;
	}
	return (dest);
}
