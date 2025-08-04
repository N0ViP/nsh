#include "expansion.h"

static void	get_value(t_list_info *expand_list, char *word)
{
	t_list	*node;

	node = creat_node(word);
	list_add_back(expand_list, node);
}
size_t	expand_regular_word(char *str, t_list_info *expand_list)
{
	size_t	n;
	char	*word;

	n = 0;
	while (str[n] != '\0' && str[n] != '\'' && str[n] != '"'
		&& !check_if_dollar(str + n))
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		get_value(expand_list, word);
	}
	return (n);
}
