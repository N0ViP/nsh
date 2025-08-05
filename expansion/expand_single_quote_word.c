#include "expansion.h"

size_t	expand_single_quote_word(char *s, char **arg, char **hashmap)
{
	size_t	n;
	char	*word;
	char	*tmp;
	size_t	wildcard;

	n = 1;
	wildcard = 0;
	if (s[0] != '\'')
		return (0);
	while (s[n] != '\0' && s[n] != '\'')
	{
		if (s[n] == '*')
		{
			wildcard++;
		}
		n++;
	}
	if (n > 1)
	{
		add_in_wildcard_hashmap(hashmap, wildcard, false);
		word = ft_substr(s, 1, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n + 1);
}
