/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:38:34 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/02 03:38:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenization.h"

static int	get_len_of_word(char *cmd, int i)
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

static void	creat_token(t_list_info *token_info, char *cmd, int i, int j)
{
	t_list	*node;
	char	*word;

	word = ft_substr(cmd, i, i + j);
	node = creat_node(word);
	if (!word || !node)
	{
		free(word);
		free(node);
		free(cmd);
		free_list(&token_info, free_token);
		exit (1);
	}
	token_info->size++;
	add_node_back(token_info, node);
}

static t_list_info	*init_tokens_struct(char *cmd)
{
	t_list_info	*token_info;

	token_info = malloc(sizeof(t_list_info));
	if (!token_info)
	{
		free(cmd);
		exit(1);
	}
	token_info->list = NULL;
	token_info->size = 0;
	token_info->tail = NULL;
	return (token_info);
}

t_list_info	*tokenize(char *cmd)
{
	t_list_info	*token_info;
	int			i;
	int			j;

	i = 0;
	token_info = init_tokens_struct(cmd);
	while (cmd[i])
	{
		i += skip_spaces(cmd, i);
		j = get_len_of_word(cmd, i);
		if (j == -1)
		{
			free(cmd);
			free_list(&token_info, free_token);
			write(2, "unclosed quotes\n", 16);
			return (NULL);
		}
		if (j != 0)
		{
			creat_token(token_info, cmd, i, j);
			i += j;
		}
	}
	return (token_info);
}
