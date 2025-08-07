#include "expansion.h"

static void	split_val(t_info *info, t_list_info *arg_list, char *val)
{
	char	*splited_val;
	bool	space_in_the_start;
	bool	space_in_the_end;
	size_t	i;

	i = 0;
	splited_val = ft_split(val, " \t\n");
	space_in_the_start = ft_isspace(val[0]);
	space_in_the_end = ft_isspace(val[ft_strlen(val) - 1]);
	if (space_in_the_start)
	{
		
	}
	while (splited_val[i])
	{
		
	}
}

static void	get_value(t_info *info, t_list_info *arg_list, char *val, bool rm_spaces)
{
	char	*tmp;

	if (val)
	{
		if (!rm_spaces)
		{
			tmp = join_two_strings(info->word, val, "");
			info->word = tmp;
			return ;
		}
		split_val(info, arg_list, val);
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
	get_value(info, arg_list, val, rm_spaces);
	return (n);
}
