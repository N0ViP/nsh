#include "built-in.h"

char **shell_cwd(void)
{
	static char	*cwd = NULL;
	return (&cwd);
}

char *update_cwd(void)
{
	char *new_cwd;
	char **old_cwd;

    old_cwd = shell_cwd();
	new_cwd = getcwd(NULL, 0);
    *old_cwd = new_cwd;
    return (*old_cwd);
}

int	built_in_pwd(void)
{
	char    *cwd;

	cwd = *shell_cwd();
	if (!cwd)
		return (EXIT_FAILURE);
	write(STDERR_FILENO, cwd, ft_strlen(cwd));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}