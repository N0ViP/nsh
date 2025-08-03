/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/03 17:28:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "expansion.h"

t_list_info	*expander(char *str, t_list_info *expand)
{
	t_list_info	*value;
	size_t		n;

	value = init_list_info_struct();
	if (!value)
		return (NULL);
	while (*str)
	{
		n = expand_regular_word(str, value);
		str += n;
		n = expand_single_quote_word(str, value);
		str += n;
		n = expand_double_quote_word(str, value);
		str += n;
		n = expand_dollar_word(str, value);
		str += n;
	}
	return (value);
}

char **expansion(t_list *lst)
{
	t_list_info	*expand;
	char		**res;
	
	expand = init_list_info_struct();
	if (!expand)
		return (NULL);
	while (lst)
	{
		if (expander(((t_token *)lst->content)->value, expand))
			return (free(expand), NULL);
		lst = lst->next;
	}
	res = create_array(expand);
	return (res);
}
