#include "expansion.h"

static void	get_value(t_list_info *value, char *word, bool wildcard)
{
	t_list	*node;

	if (!wildcard)
	{
		node = creat_node(word);
		list_add_back(value, node);
	}
	else
	{
		ft_get_wildcard(value, word);
	}
}
size_t	expand_regular_word(char *str, t_list_info *value)
{
	size_t	n;
	bool	wildcard;
	char	*word;

	n = 0;
	wildcard = false;
	while (str[n] != '\0' && str[n] != '\'' && str[n] != '"'
		&& (str[n] != '$' || !ft_isalpha(str[n + 1]) || str[n + 1] != '_'))
	{
		if (str[n] == '*')
		{
			wildcard = true;
		}
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		get_value(value, word, wildcard);
	}
	return (n);
}
