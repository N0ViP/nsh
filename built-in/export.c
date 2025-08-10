#include "built-in.h"

void	export(char **args)
{
	size_t	i;

	i = 0;
	if (!args[1])
	{
		print_env();
	}
	else
	{
		if (check_name(args[1]))
		{
			ft_getenv(ADD_IN_ENV, args[1]);
		}
		else
		{
			;
		}
	}
}
