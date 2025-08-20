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
	info->hashmap = NULL;
	info->str = str;
	info->ex_word = init_list_info_struct();
}

t_list_info *expander(char *str)
{
	t_list_info	*arg_list;
	t_info		info;

	init_info_struct(&info, str);
	arg_list = init_list_info_struct();
	while (*(info.str))
	{
		info.str += expand_regular_word(&info, regular_word_checker, true);
		info.str += expand_single_quote_word(&info);
		info.str += expand_double_quotes_word(&info);
		info.str += expand_dollar_word(&info, arg_list, true);
	}
	process_arg(&info, arg_list);
	return (arg_list);
}
