#include "expansion.h"

size_t	get_normal_word(char *str, t_list_info *tmp_value)
{
	size_t	n;
	t_list	*node;
	char	*word;

	n = 0;
	while (!check_if_dollar(str + n))
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		node = creat_node(word);
		list_add_back(tmp_value, node);
	}
}

size_t	expand_double_quote_word(char *str, t_list_info *value)
{
	char		*word;
	t_list_info	*tmp_value;
	size_t		n;

	n = 1;
	if (str[0] != '"')
	{
		retrun (0);
	}
	tmp_value = init_list_info_struct();
	while (str[n] != '\0' && str[n] != '"')
	{
		n = get_normal_word(str + n, tmp_value);
		n = get_dollar_word(str + n, tmp_value);
	}
	return (n + 1);
}
