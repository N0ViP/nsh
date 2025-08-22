/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_two_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:35:13 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:35:14 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*join_two_strings(char *s1, char *s2, char *delemiter)
{
	char	*arr[3];
	char	*join;

	if (!s1)
	{
		s1 = "";
	}
	arr[0] = s1;
	arr[1] = s2;
	arr[2] = NULL;
	join = ft_strjoin(arr, delemiter);
	return (join);
}
