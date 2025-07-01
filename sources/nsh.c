#include "nsh.h"

t_tokens	*tokenize(char *cmd)
{
	t_tokens	*tokens;
	t_tokens	*node;
	char		*token;
	int			i;
	int			j;
	int			check_quote;
	int			check_double_quotes;

	i = 0;
	j = 0;
	check_quote = 0;
	check_double_quotes = 0;
	tokens = NULL;
	while (cmd[i])
	{
		j = 0;
		while (ft_isspace(cmd[i]))
		{
			i++;
		}
		while (cmd[i + j] && !ft_isspace(cmd[i + j]))
		{
			if (cmd[i + j] == "\"")
			{
				check_double_quotes++;
			}
			else if (cmd[i + j] == "\'")
			{
				check_quote++;
			}
			j++;
		}
		if (j != 0)
		{
			token = ft_substr(cmd, i, i + j);
			node = creat_token_node(token);
			if (!token || !node)
			{
				free(cmd);
				free_tokens(tokens);
				exit (1);
			}
			add_node_back(&tokens, node);
		}
	}
	if (check_double_quotes % 2 != 0 || check_quote % 2 != 0)
	{
		free(cmd);
		free_tokens(tokens);
		write(2, "unclosed quote\n", 15);
		exit (1);
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
