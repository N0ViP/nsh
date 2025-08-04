#include "expansion.h"

size_t	expand_single_quote_word(char *str, t_list_info *value)
{
	size_t	n;
	char	*word;
	t_list	*node;

	n = 1;
	if (str[0] != '\'')
		return (0);
	while (str[n] != '\0' && str[n] != '\'')
	{
		n++;
	}
	if (n != 1)
	{
		word = ft_substr(str, 1, n);
		node = creat_node(word);
		list_add_back(value, node);
	}
	return (n + 1);
}
