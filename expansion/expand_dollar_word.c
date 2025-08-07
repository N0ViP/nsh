#include "expansion.h"

static void	add_word_in_arg_list(t_info *info, t_list_info *arg_list)
{
	t_list_info	*list;

	if (info->word == NULL)
	{
		return ;
	}
	list = expand_wildcard(info->word);
	join_list(arg_list, list);
	info->word = NULL;
}

static void	split_val(t_info *info, t_list_info *arg_list, char *val, char **splited_val)
{
	
	bool	has_leading_space;
	bool	has_trailing_space;
	size_t	i;

	i = 1;
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

static void	get_wildcard(char **splited_val, t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	info->wildcard = 0;
	while (splited_val[i])
	{
		j = 0;
		while (splited_val[i][j])
		{
			if (splited_val[i][j])
			{
				info->wildcard++;
			}
			j++;
		}
		i++;
	}
	add_in_wildcard_hashmap(info, true);
}

static void	get_value(t_info *info, t_list_info *arg_list, char *val, bool rm_spaces)
{
	char	*tmp;
	char	**splited_val;

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
	splited_val = ft_split(val, WHITE_SPACE);
	get_wildcard(splited_val, info);
	split_val(info, arg_list, val, splited_val);
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
