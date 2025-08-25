/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:00:09 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/25 08:04:36 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static void	get_wildcard(char *val, t_info *info, bool ex_wdc)
{
	size_t	i;

	i = 0;
	info->wildcard = 0;
	while (val[i])
	{
		if (val[i])
		{
			info->wildcard++;
		}
		i++;
	}
	add_in_wildcard_hashmap(info->wildcard, CURR_OFFSET, ex_wdc);
}

static void	expand_value(t_info *info, t_list_info *arg_list, char *val,
		bool rm_spaces)
{
	t_list	*node;
	char	**splited_val;
	size_t	i;

	i = 0;
	if (!val)
	{
		handle_empty_value(info, rm_spaces);
		return ;
	}
	if (!rm_spaces)
	{
		get_wildcard(val, info, false);
		node = creat_node(val);
		list_add_back(info->ex_word, node);
		info->len += ft_strlen(val);
		return ;
	}
	splited_val = ft_split(val, WHITE_SPACE);
	while (splited_val[i])
	{
		get_wildcard(splited_val[i], info, true);
		i++;
	}
	process_and_split_value(info, arg_list, val, splited_val);
}

static char	*get_value(char *key)
{
	char	*value;
	int		exit_status;

	if (key[0] == '?')
	{
		exit_status = _exit_status(EXTRACT, 0);
		value = ft_itoa(exit_status);
	}
	else
	{
		value = get_var_value(key);
	}
	return (value);
}

static size_t	get_key_len(char *str)
{
	size_t	n;

	n = 1;
	while (str[n] != '\0' && (ft_isalnum(str[n]) || str[n] == '_'))
	{
		n++;
	}
	return (n);
}

size_t	expand_dollar_word(t_info *info, t_list_info *arg_list, bool rm_spaces)
{
	char	*key;
	char	*val;
	size_t	n;

	n = 1;
	if (!check_if_dollar(info->str))
	{
		return (0);
	}
	if (info->str[n] != '?')
	{
		n += get_key_len(&info->str[1]);
	}
	else
	{
		n++;
	}
	key = ft_substr(info->str, 1, n);
	val = get_value(key);
	expand_value(info, arg_list, val, rm_spaces);
	return (n);
}
