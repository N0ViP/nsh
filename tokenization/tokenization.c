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

int	get_word_len(char *str)
{
	int		j;
	char	quote;

	j = 0;
	while (str[j] && !ft_isspace(str[j]))
	{
		if (str[j] == '\"' || str[j] == '\'')
		{
			quote = str[j];
			j++;
			while (str[j] && str[j] != quote)
			{
				j++;
			}
			if (str[j] != quote)
			{
				return (-1);
			}
		}
		j++;
	}
	return (j);
}

static void	creat_token(t_list_info *token_info, char *cmd,
						enum e_operator operator, int j)
{
	t_list	*node;
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
	{
		free(cmd);
		free_list(&token_info, free_token);
		exit (1);
	}
	token->value = ft_substr(cmd, 0, j);
	token->type = operator;
	node = creat_node(token);
	if (!token->value || !node)
	{
		free(token->value);
		free(node);
		free(cmd);
		free_list(&token_info, free_token);
		exit (1);
	}
	node->content = token;
	token_info->size++;
	add_node_back(token_info, node);
}

static int	extract_token_and_type(t_list_info *token_info, char *cmd)
{
	int				j;
	enum e_operator	operator;

	j = 0;
	operator = check_token(cmd);
	if (operator == 0)
	{
		j = get_word_len(cmd);
		if (j == -1)
		{
			return (-1);
		}
	}
	else if (operator >= 1 && operator <= 4)
	{
		j = 2;
	}
	else
	{
		j = 1;
	}
	creat_token(token_info, cmd, operator, j);
	return (j);
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
		if (!cmd[i])
		{
			break ;
		}
		j = extract_token_and_type(token_info, cmd + i);
		if (j == -1)
		{
			free(cmd);
			free_list(&token_info, free_token);
			write(2, "unclosed quotes\n", 16);
			return (NULL);
		}
		i += j;
	}
	return (token_info);
}
