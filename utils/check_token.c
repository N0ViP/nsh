/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 06:38:22 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/22 06:52:46 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

enum e_type	check_token(char *token)
{
	enum e_type	type;

	if (token[0] == '|' && token[1] == '|')
		type = OP_OR;
	else if (token[0] == '&' && token[1] == '&')
		type = OP_AND;
	else if (token[0] == '<' && token[1] == '<')
		type = OP_HEREDOC;
	else if (token[0] == '>' && token[1] == '>')
		type = OP_APPEND;
	else if (token[0] == '|')
		type = OP_PIPE;
	else if (token[0] == '>')
		type = OP_REDIR_OUT;
	else if (token[0] == '<')
		type = OP_REDIR_IN;
	else if (token[0] == '(')
		type = OP_OPEN_PARENTHESE;
	else if (token[0] == ')')
		type = OP_CLOSED_PARENTHESE;
	else
		type = WORD;
	return (type);
}
