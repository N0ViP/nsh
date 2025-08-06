/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/06 00:54:57 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

char	*expander(char *str)
{
	char	*word;
	char	*hashmap;
	size_t	n;

	word = "";
	hashmap = NULL;
	while (*str)
	{
		n = expand_regular_word(str, &word, &hashmap);
		str += n;
		n = expand_single_quote_word(str, &word, &hashmap);
		str += n;
		n = expand_double_quotes_word(str, &word, &hashmap);
		str += n;
		n = expand_dollar_word(str, &word, &hashmap, true);
		str += n;
	}
	expand_wildcard(&word, &hashmap);
	return (word);
}
