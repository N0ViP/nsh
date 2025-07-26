/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/26 15:28:37 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "nsh.h"

int	*get_normal_word(char *str,t_list_info *value)
{
	int		n;
	char	*word;
	t_list	*node;

	n = 0;
	while (str[n] != '\0' && str[n] != '\''
		&& str[n] != '"' && str[n] != '$')
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		node = creat_node(word);
		if (!word || !value || !node)
		{
			free(word);
			free(value);
			return (-1);
		}
		list_add_back(value, node);
	}
	return (n);
}

t_list_info	*expander(char *str, t_list_info *expand)
{
	t_list_info	*value;
	int			n;

	value = init_list_info_struct();
	if (!value)
		return (NULL);
	while (*str)
	{
		n = get_normal_word(str, value);
		if (n == -1)
			return (NULL);
		str += n;
		n = get_single_quote_word(str, value);
		if (n == -1)
			return (NULL);
		str += n;
		n = get_double_quote_word(str, value);
		if (n == -1)
			return (NULL);
		str += n;
		n = get_dollar_word(str, value);
		if (n == -1)
			return (NULL);
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
