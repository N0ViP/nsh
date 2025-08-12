#include "built-in.h"

int	built_in_unset(char *args[])
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		ft_getenv(REMOVE_FROM_ENV, args[i]);
		i++;
	}
	return (0);
}
