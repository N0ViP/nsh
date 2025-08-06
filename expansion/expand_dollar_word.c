#include "expansion.h"

static size_t	get_wildcard(char *str)
{
	size_t	wildcard;

	wildcard = 0;
	while (*str)
	{
		if (*str == '*')
		{
			wildcard++;
		}
		str++;
	}
	return (wildcard);
}

static void	get_value(t_info *info, char *val, bool rm_spaces)
{
	char	*tmp;
	char	**splited_val; 
	size_t	wildcard;

	if (val)
	{
		if (rm_spaces)
		{
			splited_val = ft_split(val, " \t\n");
			val = ft_strjoin(splited_val, " ");
		}
		wildcard = get_wildcard(val);
		tmp = join_two_strings(*arg, val, "");
		*arg = tmp;
		if (rm_spaces)
		{
			add_in_wildcard_hashmap(info, wildcard, true);
		}
		else
		{
			add_in_wildcard_hashmap(info, wildcard, false);
		}
	}
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
	get_value(info, val, rm_spaces);
	return (n);
}
