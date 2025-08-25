/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_spliting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 06:29:51 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/25 08:04:54 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static void	finalize_and_add_arg(t_info *info, t_list_info *arg_list)
{
	process_arg(info, arg_list);
	re_init_list_info_struct(info->ex_word);
	info->len = 0;
}

static void	append_word_to_current_arg(t_info *info, char *value)
{
	t_list	*node;

	info->len += ft_strlen(value);
	node = creat_node(value);
	list_add_back(info->ex_word, node);
}

static void	append_split_args(t_info *info, t_list_info *arg_list,
		char **splited_val, bool has_trailing_space)
{
	size_t	i;

	i = 1;
	append_word_to_current_arg(info, splited_val[0]);
	if (splited_val[i] || has_trailing_space)
	{
		finalize_and_add_arg(info, arg_list);
	}
	while (splited_val[i])
	{
		append_word_to_current_arg(info, splited_val[i]);
		i++;
		if (splited_val[i] || has_trailing_space)
		{
			finalize_and_add_arg(info, arg_list);
		}
	}
}

void	process_and_split_value(t_info *info, t_list_info *arg_list,
		char *val, char **splited_val)
{
	bool	has_leading_space;
	bool	has_trailing_space;

	has_leading_space = ft_isspace(val[0]);
	has_trailing_space = ft_isspace(val[ft_strlen(val) - 1]);
	if (has_leading_space)
	{
		finalize_and_add_arg(info, arg_list);
	}
	if (splited_val[0])
	{
		append_split_args(info, arg_list, splited_val, has_trailing_space);
	}
}

void	handle_empty_value(t_info *info, bool rm_spaces)
{
	if (!rm_spaces)
	{
		utils(info, 0, 0, rm_spaces);
	}
}
