#include "expansion.h"

size_t	get_normal_word(char *str, char **arg, char **hashmap)
{
	size_t	n;
	size_t	wildcard;
	char	*word;
	char	*tmp;

	n = 0;
	wildcard = 0;
	while (str[n] != '\0' && str[n] != '"'
		&& !check_if_dollar(str + n))
	{
		if (str[n] == '*')
		{
			wildcard++;
		}
		n++;
	}
	if (n > 0)
	{
		add_in_wildcard_hashmap(hashmap, wildcard, false);
		word = ft_substr(str, 0, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n);
}

size_t	expand_double_quotes_word(char *s, char **arg, char **hashmap)
{
	char		*word;
	size_t		n;
	size_t		i;

	i = 1;
	if (s[0] != '"')
	{
		return (0);
	}
	while (s[i] != '\0' && s[i] != '"')
	{
		n = get_normal_word(s + i, arg, hashmap);
		i += n;
		n = expand_dollar_word(s + i, arg, hashmap, false);
		i += n;
	}
	return (i + 1);
}
