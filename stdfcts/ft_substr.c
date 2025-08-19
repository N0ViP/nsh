/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:39:18 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:39:19 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char *str, int i, int j)
{
	char	*res;
	int		k;

	k = 0;
	res = allocate_memory(j - i + 1);
	while (i < j)
	{
		res[k] = str[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}
