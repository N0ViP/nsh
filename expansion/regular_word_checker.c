#include "expansion.h"

bool	regular_word_checker(char *str)
{
	if (*str != '\0' && *str != '\'' && *str != '"'
		&& !check_if_dollar(str))
	{
		return (true);
	}
	return (false);
}
