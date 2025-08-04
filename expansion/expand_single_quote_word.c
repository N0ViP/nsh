#include "expansion.h"

size_t	expand_single_quote_word(char *str, char **arg)
{
	size_t	n;
	char	*word;
	char	*tmp;

	n = 1;
	if (str[0] != '\'')
		return (0);
	while (str[n] != '\0' && str[n] != '\'')
	{
		n++;
	}
	if (n > 1)
	{
		word = ft_substr(str, 1, n);
		tmp = join_two_strings(*arg, word, "");
		*arg = tmp;
	}
	return (n + 1);
}
