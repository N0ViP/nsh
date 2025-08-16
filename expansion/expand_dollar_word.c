#include "expansion.h"

static void	add_word_in_arg_list(t_info *info, t_list_info *arg_list)
{
	expand_wildcard(info, arg_list);
	re_init_list_info_struct(info->ex_word);
	info->len = 0;
}

static void	add_word_node(t_info *info, char *value)
{
	t_list	*node;

	info->len += ft_strlen(value);
	node = creat_node(value);
	list_add_back(info->ex_word, node);
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
	{
		add_word_in_arg_list(info, arg_list);
	}
	if (splited_val[0])
	{
		add_word_node(info, splited_val[0]);
		while (splited_val[i])
		{
			if (splited_val[i] || has_trailing_space)
			{
				add_word_in_arg_list(info, arg_list);
			}
			add_word_node(info, splited_val[i]);
			i++;
		}
	}
}

// static void	get_wildcard(char **splited_val, t_info *info)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	info->wildcard = 0;
// 	while (splited_val[i])
// 	{
// 		j = 0;
// 		while (splited_val[i][j])
// 		{
// 			if (splited_val[i][j])
// 			{
// 				info->wildcard++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	add_in_wildcard_hashmap(info, true);
// }

static void	expand_value(t_info *info, t_list_info *arg_list, char *val, bool rm_spaces)
{
	t_list	*node;
	char	**splited_val;

	if (!val)
	{
		return ;
	}
	if (!rm_spaces)
	{
		// add_in_wildcard_hashmap(info, rm_spaces);
		node = creat_node(val);
		list_add_back(info->ex_word, node);
		info->len += ft_strlen(val);
		return ;
	}
	// get_wildcard(splited_val, info);
	splited_val = ft_split(val, WHITE_SPACE);
	split_val(info, arg_list, val, splited_val);
}

static char	*get_value(char *key)
{
	char	*value;
	int		exit_status;

	if (key[0] == '?')
	{
		exit_status = _exit_status(GET_VALUE, 0);
		value = ft_itoa(exit_status);
	}
	else
	{
		value = get_var_value(key);
	}
	return (value);
}

size_t	get_key_len(char *str)
{
	size_t	n;

	n = 1;
	while (str[n] != '\0'
		&& (ft_isalnum(str[n]) || str[n] == '_'))
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
