#include "expansion.h"

size_t	expand_regular_word(char *s, char **arg, char **hashmap)
{
	size_t	n;
	char	*word;
	char	*tmp;
	size_t	wildcard;

	n = 0;
	wildcard = 0;
	while (s[n] != '\0' && s[n] != '\'' && s[n] != '"'
		&& !check_if_dollar(s + n))
	{
		if (s[n] == '*')
		{
			wildcard++;
		}
		n++;
	}
	if (n > 0)
	{
		add_in_wildcard_hashmap(hashmap, wildcard, true);
		word = ft_substr(s, 0, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n);
}
