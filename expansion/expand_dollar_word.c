#include "expansion.h"

static void	add_dollar_expand(char **arg, char *key, bool remove_spaces)
{
	char	*val;
	char	*tmp;
	char	**splited_val; 

	val = get_var_value(key);
	if (val)
	{
		if (remove_spaces)
		{
			splited_val = ft_split(val, " \t\n");
			val = ft_strjoin(splited_val, " ");
		}
		tmp = join_two_strings(*arg, val, "");
		*arg = tmp;
	}
}

size_t	expand_dollar_word(char *str, char **arg, bool remove_spaces)
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
	add_dollar_expand(arg, key, remove_spaces);
	return (n);
}
