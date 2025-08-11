/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:38:34 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/11 07:58:44 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenization.h"

static size_t	get_word_len(char **s)
{
	size_t	j;
	char	quote;

	j = 0;
	while ((*s)[j] && !ft_isspace((*s)[j]) && !ft_strchr("|><()", (*s)[j]))
	{
		if ((*s)[j] == '&' && (*s)[j + 1] == '&')
			break ;
		if ((*s)[j] == '"' || (*s)[j] == '\'')
		{
			quote = (*s)[j++];
			while ((*s)[j] && (*s)[j] != quote)
			{
				j++;
			}
			if ((*s)[j] != quote)
			{
				*s = NULL;
				return (0);
			}
		}
		j++;
	}
	return (j);
}

static bool	creat_token(t_list_info *token_info, char *ptr,
						enum e_operator operator, int idx)
{
	t_list	*node;
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
	{
		return (false);
	}
	token->type = operator;
	token->value = ft_substr(ptr, 0, idx);
	node = creat_node(token);
	if (!token->value || !node)
	{
		free(token->value);
		free(node);
		return (false);
	}
	list_add_back(token_info, node);
	return (true);
}

static size_t	extract_token_and_type(t_list_info *token_info, char **ptr)
{
	size_t			j;
	enum e_operator	operator;

	j = 1;
	operator = check_token(*ptr);
	if (operator == WORD)
	{
		j = get_word_len(ptr);
		if (*ptr == NULL)
		{
			_exit_status(SAVE_VALUE, 2);
			return (free(*ptr), *ptr = NULL, free_list(&token_info, free_token),
				write(2, "unclosed quotes\n", 16),0);
		}
	}
	else if (operator == OP_OR || operator == OP_AND
		|| operator == OP_APPEND || operator == OP_HEREDOC)
		j = 2;
	if (!creat_token(token_info, *ptr, operator, j))
	{
		free(*ptr);
		*ptr = NULL;
		free_list(&token_info, free_token);
		exit (EXIT_FAILURE);
	}
	*ptr += j;
	return (j);
}

t_list_info	*tokenize(char *cmd)
{
	t_list_info	*token_info;
	char		*ptr;

	ptr = cmd;
	ptr += skip_spaces(ptr, 0);
	if (!*ptr)
		return (NULL);
	token_info = init_list_info_struct();
	if (!token_info)
	{
		free(cmd);
		exit(EXIT_FAILURE);
	}
	while (*ptr)
	{
		extract_token_and_type(token_info, &ptr);
		if (ptr == NULL)
			return (NULL);
		ptr += skip_spaces(ptr, 0);
		
	}
	return (token_info);
}
