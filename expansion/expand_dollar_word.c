#include "expansion.h"

static void	add_word_in_arg_list(t_info *info, t_list_info *arg_list)
{
	t_list	*node;

	if (info->word == NULL)
	{
		return ;
	}
	node = creat_node(info->word);
	list_add_back(arg_list, node);
	info->word = NULL;
}

static void	split_val(t_info *info, t_list_info *arg_list, char *val)
{
	char	**splited_val;
	bool	has_leading_space;
	bool	has_trailing_space;
	size_t	i;

	i = 1;
	splited_val = ft_split(val, WHITE_SPACE);
	has_leading_space = ft_isspace(val[0]);
	has_trailing_space = ft_isspace(val[ft_strlen(val) - 1]);
	if (has_leading_space)
		add_word_in_arg_list(info, arg_list);
	else
	{
		info->word = join_two_strings(info->word, splited_val[0], "");
		if (splited_val[1] || has_trailing_space)
			add_word_in_arg_list(info, arg_list);
	}
	while (splited_val[i])
	{
		info->word = splited_val[i];
		i++;
		if (splited_val[i] || has_trailing_space)
			add_word_in_arg_list(info, arg_list);
	}
}

static void	get_value(t_info *info, t_list_info *arg_list, char *val, bool rm_spaces)
{
	char	*tmp;

	if (!val)
	{
		return ;
	}
	if (!rm_spaces)
	{
		tmp = join_two_strings(info->word, val, "");
		info->word = tmp;
		return ;
	}
	split_val(info, arg_list, val);
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
	while (info->str[n] != '\0'
		&& (ft_isalnum(info->str[n]) || info->str[n] == '_'))
	{
		n++;
	}
	key = ft_substr(info->str, 1, n);
	val = get_var_value(key);
	get_value(info, arg_list, val, rm_spaces);
	return (n);
}
