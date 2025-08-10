#include "expansion.h"

bool	check_if_dollar(char *str)
{
	if (str[0] != '$' || (!ft_isalpha(str[1]) && str[1] != '_' && str[1] != '?'))
	{
		return (false);
	}
	return (true);
}
