#include "expansion.h"

size_t	expand_single_quote_word(t_info *info)
{
	size_t	n;

	n = 1;
	info->wildcard = 0;
	if (info->str[0] != '\'')
	{
		return (0);
	}
	while (info->str[n] != '\'')
	{
		if (info->str[n] == '*')
		{
			info->wildcard++;
		}
		n++;
	}
	if (n >= 1)
	{
		utils(info, 1, n, false);
	}
	return (n + 1);
}
