#include "expansion.h"

size_t	expand_double_quotes_word(t_info *info)
{
	char		*word;
	size_t		i;

	i = 1;
	if (info->str[0] != '"')
	{
		return (0);
	}
	while (info->str[i] != '"')
	{
		i += expand_regular_word(info, double_quotes_checker, false);
		i += expand_dollar_word(info, NULL, false);
	}
	return (i + 1);
}
