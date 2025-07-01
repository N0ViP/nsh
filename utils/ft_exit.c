#include "utils.h"

void	ft_exit(int err)
{
	if (err == 1)
	{
		free(cmd);
		free_tokens(tokens);
		exit (1);
	}
}