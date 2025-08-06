#include "expansion.h"

bool	double_quotes_checker(char *str)
{
	if (*str != '\0' && *str != '"'
		&& !check_if_dollar(str))
	{
		return (true);
	}
	return (false);
}
