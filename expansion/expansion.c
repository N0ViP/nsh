/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/05 00:10:53 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

char	*expander(char *str)
{
	char		*word;
	size_t		n;

	word = "";
	while (*str)
	{
		n = expand_regular_word(str, &word);
		str += n;
		n = expand_single_quote_word(str, &word);
		str += n;
		n = expand_double_quote_word(str, &word);
		str += n;
		n = expand_dollar_word(str, &word, true);
		str += n;
	}
	return (word);
}
