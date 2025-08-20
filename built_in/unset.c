#include "built-in.h"

int	built_in_unset(t_cmd *cmd_args)
{
    char   	**args;
	size_t	i;

	i = 1;
    args = cmd_args->args;
	while (args[i])
	{
		ft_getenv(REMOVE_FROM_ENV, args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
