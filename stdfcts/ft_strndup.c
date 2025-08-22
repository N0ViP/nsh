/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:30 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:31 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdfcts.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = allocate_memory(n + 1);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen(s);
	dup = allocate_memory(n + 1);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
