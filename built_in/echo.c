#include "built-in.h"

int	built_in_echo(char **arr)
{
	char	*args;
	bool	new_line;

	arr++;
	new_line = true;
	if (*arr && !ft_strcmp(*arr, "-n"))
	{
		arr++;
		new_line = false;
	}
	args = ft_strjoin(arr, " ");
	if (new_line)
	{
		args = join_two_strings(args, "\n", "");
	}
	write(1, args, ft_strlen(args));
	return (EXIT_SUCCESS);
}
