#include "getenv.h"

int	ft_strcmp_env(char *s1, char *s2)
{
	while (*s1 && *s1 != '=' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2 || (*s1 == '\0' && *s2 == '='))
	{
		return (1);
	}
	if (*s1 == '=' && *s2 == '\0')
	{
		return (0);
	}
	return (-1);
}
