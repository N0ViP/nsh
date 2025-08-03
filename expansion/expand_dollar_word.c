#include "expansion.h"

static void	handle_val(t_list_info *value, char *val)
{
	char	**splited_val; 
	t_list	*node;
	
	splited_val = ft_split(val, " \t\n");
	free(val);
	val = ft_strjoin(splited_val, " ");
	node = creat_node(val);
	list_add_back(value, node);
}

static void	get_add_dollar_expand(t_list_info *value, char *str, int i, int j)
{
	char	*key;
	char	*val;

	key = ft_substr(str, i, j);
	val = get_var_value(key);
	free(key);
	if (val)
	{
		handle_val(value, val);
	}
}

size_t	expand_dollar_word(char *str, t_list_info *value)
{
	size_t		n;

	n = 1;
	if (str[0] != '$' || str[1] == '\0' || str[1] == '$')
	{
		return (0);
	}
	if (ft_isdigit(str[n]))
	{
		while (str[n] != '\0' && (ft_isalnum(str[n]) || str[n] == '_'))
		{
			n++;
		}
	}
	if (n != 1)
	{
		get_add_dollar_expand(value, str, 1, n);
	}
	return (n);
}
