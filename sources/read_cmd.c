#include "nsh.h"

bool	read_command(char **cmd)
{
	*cmd = readline("\e[32mnsh$\e[0m ");
	if (!*cmd)
    {
		write(STDERR_FILENO, "exit\n", 5);//
		exit(0);
    }
	else if (!**cmd)
	{
		free(*cmd);
		return (false);
	}
	add_history(*cmd);
	return (true);
}
