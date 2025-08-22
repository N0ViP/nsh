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

static void	add_to_list(t_list **tokens, t_list *new_node)
{
	t_list	*current;

	if (!*tokens)
	{
		*tokens = new_node;
	}
	else
	{
		current = *tokens;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

static t_list	*creat_token(char *ptr, t_type type, int idx)
{
	t_list	*node;
	t_token	*token;

	token = allocate_memory(sizeof(t_token));
	token->type = type;
	token->value = ft_substr(ptr, 0, idx);
	node = creat_node(token);
	return (node);
}

static size_t	extract_token_and_type(t_list **tokens, char **ptr)
{
	t_type	type;
	size_t	j;

	j = 1;
	type = check_token(*ptr);
	if (type == WORD)
	{
		j = get_word_len(ptr);
		if (*ptr == NULL)
		{
			_exit_status(UPDATE, 2);
			return (write(2, "unclosed quotes\n", 16), 0);
		}
	}
	else if (type == OP_OR || type == OP_AND || type == OP_APPEND
		|| type == OP_HEREDOC)
		j = 2;
	add_to_list(tokens, creat_token(*ptr, type, j));
	*ptr += j;
	return (j);
}

t_list	*tokenize(char *cmd)
{
	t_list	*tokens;

	add_allocation(cmd);
	cmd += skip_spaces(cmd, 0);
	if (!*cmd)
		return (NULL);
	tokens = NULL;
	while (*cmd)
	{
		extract_token_and_type(&tokens, &cmd);
		if (cmd == NULL)
			return (NULL);
		cmd += skip_spaces(cmd, 0);
	}
	return (tokens);
}
