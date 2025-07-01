/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:37:28 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:37:37 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

int	get_len_of_word(char *cmd, int i)
{
	int		j;
	char	quote;

	j = 0;
	while (cmd[i + j] && !ft_isspace(cmd[i + j]))
	{
		if (cmd[i + j] == '\"' || cmd[i + j] == '\'')
		{
			quote = cmd[i + j];
			j++;
			while (cmd[i + j] && cmd[i + j] != quote)
			{
				j++;
			}
			if (cmd[i + j] != quote)
			{
				return (-1);
			}
		}
		j++;
	}
	return (j);
}

void	creat_token(t_tokens **tokens, char *cmd, int i, int j)
{
	t_tokens	*node;
	char		*word;

	word = ft_substr(cmd, i, i + j);
	node = creat_token_node(word);
	if (!word || !node)
	{
		free(word);
		free(cmd);
		free_tokens(*tokens);
		exit (1);
	}
	add_node_back(tokens, node);
}

t_tokens	*tokenize(char *cmd)
{
	t_tokens	*tokens;
	int			i;
	int			j;

	i = 0;
	tokens = NULL;
	while (cmd[i])
	{
		i += skip_spaces(cmd, i);
		j = get_len_of_word(cmd, i);
		if (j == -1)
		{
			free(cmd);
			free_tokens(tokens);
			write(2, "unclosed quotes\n", 16);
			return (NULL);
		}
		if (j != 0)
		{
			creat_token(&tokens, cmd, i, j);
			i += j;
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
		cmd = readline("\e[32mnsh$\e[0m ");
		if (cmd && *cmd)
			add_history(cmd);
		tokens = tokenize(cmd);
		while (tokens)
		{
			printf("%s\n", tokens->word);
			tokens = tokens->next;
		}
	}
}
