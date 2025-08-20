#include "expansion.h"

size_t	expand_regular_word(t_info *info, bool (*checker)(char *), bool ex_wdc)
{
	size_t	n;

	n = 0;
	info->wildcard = 0;
	while (checker(info ->str + n))
	{
		if (info->str[n] == '*')
		{
			info->wildcard++;
		}
		n++;
	}
	if (n > 0)
	{
		utils(info, 0, n, ex_wdc);
	}
	// else if (ex_wdc == false)
	// {
	// 	utils(info, 0, 1, ex_wdc);
	// }
	return (n);
}
