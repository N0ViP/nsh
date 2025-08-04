#include "getenv.h"

bool	ft_strcmp_env(char *s1, char *s2)
{
	while (*s1 && *s1 != '=' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2 && !(*s1 == '=' && *s2 == '\0'))
	{
		return (false);
	}
	return (true);
}