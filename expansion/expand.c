/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/20 16:08:15 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

static void	init_info_struct(t_info *info, char *str)
{
	info->len = 0;
	info->str = str;
	info->hashmap = add_in_wildcard_hashmap(0, RESET_OFFSET, false);
	info->ex_word = init_list_info_struct();
}

t_list_info *expander(char *str, bool ex_wdc)
{
	t_list_info	*arg_list;
	t_info		info;
	size_t		i;

	init_info_struct(&info, str);
	arg_list = init_list_info_struct();
	while (*(info.str))
	{
		i = expand_regular_word(&info, regular_word_checker, ex_wdc);
		info.str += i;
		i = expand_single_quote_word(&info);
		info.str += i;
		i = expand_double_quotes_word(&info);
		info.str += i;
		i = expand_dollar_word(&info, arg_list, ex_wdc);
		info.str += i;
	}
	process_arg(&info, arg_list);
	return (arg_list);
}
