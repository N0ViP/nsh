#include "built-in.h"

int	built_in_pwd(t_cmd *cmd_args)
{
	char    *cwd;

	(void)cmd_args;
	cwd = *shell_cwd();
	if (!cwd)
		return (EXIT_FAILURE);
	write(STDERR_FILENO, cwd, ft_strlen(cwd));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}