/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/04 06:21:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

void	expander(char *str, t_list_info *expand_list)
{
	size_t		n;

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
}

char	**expansion(t_list *lst)
{
	t_list_info	*expand_list;
	char		**res;
	
	expand_list = init_list_info_struct();
	while (lst)
	{
		expander(((t_token *)lst->content)->value, expand_list);
		lst = lst->next;
	}
	res = create_array(expand_list);
	return (res);
}
