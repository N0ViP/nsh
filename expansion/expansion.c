/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/05 04:05:38 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

char	*expander(char *str)
{
	char		*word;
	char		*hashmap;
	size_t		n;

	word = "";
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
	return (word);
}
