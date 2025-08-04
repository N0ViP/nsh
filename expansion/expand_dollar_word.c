#include "expansion.h"

static void	add_dollar_expand(t_list_info *expand_list, char *key, bool remove_spaces)
{
	char	*val;
	char	**splited_val; 
	t_list	*node;

	val = get_var_value(key);
	if (val)
	{
		if (remove_spaces)
		{
			splited_val = ft_split(val, " \t\n");
			free(val);
			val = ft_strjoin(splited_val, " ");
		}
		node = creat_node(val);
		list_add_back(expand_list, node);
	}
}

size_t	expand_dollar_word(char *str, t_list_info *expand_list, bool remove_spaces)
{
	size_t	n;
	char	*key;

	n = 1;
	if (!check_if_dollar(str))
	{
		return (0);
	}
	while (str[n] != '\0' && (ft_isalnum(str[n]) || str[n] == '_'))
	{
		n++;
	}
	key = ft_substr(str, 1, n);
	add_dollar_expand(expand_list, key, remove_spaces);
	return (n);
}
