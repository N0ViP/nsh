/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:18 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:20 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdfcts.h"

#define COUNT_SPACES true
#define COUNT_WORD false

static size_t	count_chars(char *s, char *sep, bool flag)
{
	size_t	i;

	i = 0;
	while (s[i] && check_if_match(sep, s[i]) == flag)
	{
		i++;
	}
	return (i);
}

static size_t	count_words(char *s, char *sep)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s += count_chars(s, sep, COUNT_SPACES);
		if (*s)
		{
			count++;
		}
		s += count_chars(s, sep, COUNT_WORD);
	}
	return (count);
}

static void	fill_result(char **res, char *s, char *sep, size_t word_count)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s && i < word_count)
	{
		s += count_chars(s, sep, COUNT_SPACES);
		word_len = count_chars(s, sep, COUNT_WORD);
		res[i] = ft_strndup(s, word_len);
		s += word_len;
		i++;
	}
	res[i] = NULL;
}

char	**ft_split(char *s, char *sep)
{
	size_t	word_count;
	char	**result;

	if (!s)
	{
		return (NULL);
	}
	word_count = count_words((char *)s, sep);
	result = allocate_memory((word_count + 1) * sizeof(char *));
	fill_result(result, (char *)s, sep, word_count);
	return (result);
}
