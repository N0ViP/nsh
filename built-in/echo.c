#include "built-in.h"

void	built_in_echo(char **arr)
{
	char	*args;
	bool	new_line;

	new_line = true;
	if (!ft_strcmp(*arr, "-n"))
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
}
