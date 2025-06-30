#include "nsh.h"



t_tokens	*tokenize(char *cmd)
{
	t_tokens	*tokens;
	t_tokens	*node;
	char		*token;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		j = 0;
		while (ft_isspace(cmd[i]))
		{
			i++;
		}
		while (cmd[i + j] && !ft_isspace(cmd[i + j]))
		{
			j++;
		}
		if (j != 0)
		{
			token = ft_substr(cmd, i, i + j);
			node = new_node(token);
			add_node_back(&tokens, node);
		}
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
		if (cmd && *cmd)
			add_history(cmd);
		tokens = tokenize(cmd);
	}
}
