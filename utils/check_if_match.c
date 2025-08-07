#include "utils.h"

bool	check_if_match(char *sep, char c)
{
	if (ft_strchr(sep, c))
	{
		return (true);
	}
	return (false);
}