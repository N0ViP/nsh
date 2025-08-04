#include "expansion.h"

size_t	get_normal_word(char *str, t_list_info *expand_list)
{
	size_t	n;
	t_list	*node;
	char	*word;

	n = 0;
	while (str[n] != '\0' && str[n] != '"'
		&& !check_if_dollar(str + n))
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		node = creat_node(word);
		list_add_back(expand_list, node);
	}
	return (n);
}

size_t	expand_double_quote_word(char *str, t_list_info *expand_list)
{
	char		*word;
	size_t		n;
	size_t		i;

	i = 1;
	if (str[0] != '"')
	{
		retrun (0);
	}
	while (str[i] != '\0' && str[i] != '"')
	{
		n = get_normal_word(str + i, expand_list);
		i += n;
		n = expand_dollar_word(str + i, expand_list, false);
		i += n;
	}
	return (n + 1);
}
