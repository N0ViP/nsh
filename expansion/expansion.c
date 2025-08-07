/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/07 06:46:34 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

char	**expander(char *str)
{
	t_list_info	*arg_list;
	t_list_info	*list;
	t_info		info;
	size_t		n;
	char		**res;

	info.str = str;
	info.word = NULL;
	arg_list = init_list_info_struct();
	while (*(info.str))
	{
		n = expand_regular_word(&info, regular_word_checker, true);
		info.str += n;
		n = expand_single_quote_word(&info);
		info.str += n;
		n = expand_double_quotes_word(&info);
		info.str += n;
		n = expand_dollar_word(&info, arg_list, true);
		info.str += n;
	}
	list = expand_wildcard(&info);
	join_list(arg_list, list);
	res = list_to_arr(arg_list);
	return (res);
}
