#include "expansion.h"

size_t	expand_regular_word(char *str, char **arg)
{
	size_t	n;
	char	*word;
	char	*tmp;

	n = 0;
	while (str[n] != '\0' && str[n] != '\'' && str[n] != '"'
		&& !check_if_dollar(str + n))
	{
		n++;
	}
	if (n != 0)
	{
		word = ft_substr(str, 0, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n);
}
