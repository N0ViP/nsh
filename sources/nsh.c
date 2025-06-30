#include "nsh.h"

bool	

t_tokens	*tokenize(char *cmd)
{
	t_tokens	*tokens;
	
	char		**args;
	int			i;

	i = 0;
	args = ft_split(cmd);
	free(cmd);
	if (!args)
		exit(1);
	while (args[i])
	{
		if (!add_node_back(&tokens, args))
		{
			i = 0;
			while (args[i])
				free(args[i++]);
			exit (1);
		}
		i++;
	}
	return (tokens);
}

int	main(int ac, char *av[], char *ev[])
{
	char		*cmd;
	t_tokens	*tokens;

	while (true)
	{
		cmd = readline("\e[32mnsh$\e[0m");
		if (cmd)
			add_history(cmd);
		tokens = tokenize(cmd);
	}
}
