#include "built-in.h"

int	built_in_echo(t_cmd *cmd_args)
{
	char	*args;
    char   	**argv;
	bool	new_line;

    argv = cmd_args->args;
	new_line = true;
	argv++;
	if (*argv && !ft_strcmp(*argv, "-n"))
	{
		argv++;
		new_line = false;
	}
	args = ft_strjoin(argv, " ");
	if (new_line)
	{
		args = join_two_strings(args, "\n", "");
	}
	write(1, args, ft_strlen(args));
	return (EXIT_SUCCESS);
}
