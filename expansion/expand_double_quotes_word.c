#include "expansion.h"

size_t	expand_double_quotes_word(t_info *info)
{
	size_t		i;

	if (info->str[0] != '"')
	{
		return (0);
	}
	info->str++;
	if (*info->str == '"')
	{
		utils(info, 0, 0, false);
	}
	while (*(info->str) != '"')
	{
		i = expand_regular_word(info, double_quotes_checker, false);
		info->str += i;
		i = expand_dollar_word(info, NULL, false);
		info->str += i;
	}
	info->str++;
	return (0);
}
