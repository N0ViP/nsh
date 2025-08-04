#include "expansion.h"

size_t	get_normal_word(char *str, t_list_info *tmp_value)
{
	size_t	n;
	t_list	*node;
	char	*word;

	n = 0;
	while (str[n] != '\0' && !check_if_dollar(str + n))
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		node = creat_node(word);
		list_add_back(tmp_value, node);
	}
	return (n);
}

size_t	expand_double_quote_word(char *str, t_list_info *value)
{
	char		*word;
	t_list_info	*tmp_value;
	size_t		n;
	size_t		i;

	i = 1;
	if (str[0] != '"')
	{
		retrun (0);
	}
	tmp_value = init_list_info_struct();
	while (str[i] != '\0' && str[i] != '"')
	{
		n = get_normal_word(str + i, tmp_value);
		i += n;
		n = get_dollar_word(str + i, tmp_value);
		i += n;
	}
	return (n + 1);
}
