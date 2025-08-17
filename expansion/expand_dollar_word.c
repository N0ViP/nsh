#include "expansion.h"

static void	finalize_and_add_arg(t_info *info, t_list_info *arg_list)
{
	expand_wildcard(info, arg_list);
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

static void	append_split_args(t_info *info, t_list_info *arg_list, char **splited_val, bool has_trailing_space)
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

static void	process_and_split_value(t_info *info, t_list_info *arg_list, char *val, char **splited_val)
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

// static void	get_wildcard(char *val, t_info *info, bool ex_wdc)
// {
// 	size_t	i;
// 
// 	i = 0;
// 	info->wildcard = 0;
// 	while (splited_val[i])
// 	{
// 		if (splited_val[i][j])
// 		{
// 			info->wildcard++;
// 		}
// 		i++;
// 	}
// 	add_in_wildcard_hashmap(info, ex_wdc);
// }

static void	expand_value(t_info *info, t_list_info *arg_list, char *val, bool rm_spaces)
{
	t_list	*node;
	char	**splited_val;
	size_t	i;

	i = 0;
	if (!val)
	{
		return ;
	}
	if (!rm_spaces)
	{
		// get_wildcard(val, info, false);
		node = creat_node(val);
		list_add_back(info->ex_word, node);
		info->len += ft_strlen(val);
		return ;
	}
	splited_val = ft_split(val, WHITE_SPACE);
	while (splited_val[i])
	{
		// get_wildcard(splited_val[i], info, true);
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
