#include "expansion.h"

size_t	get_normal_word(char *str, char **arg)
{
	size_t	n;
	char	*word;
	char	*tmp;

	n = 0;
	while (str[n] != '\0' && str[n] != '"'
		&& !check_if_dollar(str + n))
	{
		n++;
	}
	if (n > 0)
	{
		word = ft_substr(str, 0, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n);
}

size_t	expand_double_quote_word(char *str, char **arg)
{
	char		*word;
	size_t		n;
	size_t		i;

	i = 1;
	if (str[0] != '"')
	{
		return (0);
	}
	while (str[i] != '\0' && str[i] != '"')
	{
		n = get_normal_word(str + i, arg);
		i += n;
		n = expand_dollar_word(str + i, arg, false);
		i += n;
	}
	return (n + 1);
}
