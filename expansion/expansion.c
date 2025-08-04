/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/04 21:38:17 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

t_list	*expander(char *str)
{
	t_list_info	*expand_list;
	t_list		*node;
	size_t		n;

	expand_list = init_list_info_struct();
	while (*str)
	{
		n = expand_regular_word(str, expand_list);
		str += n;
		n = expand_single_quote_word(str, expand_list);
		str += n;
		n = expand_double_quote_word(str, expand_list);
		str += n;
		n = expand_dollar_word(str, expand_list, true);
		str += n;
	}
	node = join_all_nodes(expand_list);
	return (node);
}
