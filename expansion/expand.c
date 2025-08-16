/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/16 12:53:49 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

t_list_info *expander(char *str)
{
	t_list_info	*arg_list;
	t_info		info;

	info.len = 0;
	info.str = str;
	info.ex_word = init_list_info_struct();
	arg_list = init_list_info_struct();
	while (*(info.str))
	{
		info.str += expand_regular_word(&info, regular_word_checker, true);
		info.str += expand_single_quote_word(&info);
		info.str += expand_double_quotes_word(&info);
		info.str += expand_dollar_word(&info, arg_list, true);
	}
	expand_wildcard(&info, arg_list);
	return (arg_list);
}
