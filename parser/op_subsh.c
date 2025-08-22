/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_subsh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:48 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 07:00:32 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

t_tree	*new_operator_branch(t_list *tokens, t_list *split)
{
	t_list	*op_node;
	t_list	*right;
	t_tree	*node;

	op_node = split->next;
	right = op_node->next;
	split->next = NULL;
	node = allocate_memory(sizeof(t_tree));
	node->type = ((t_token *)op_node->content)->type;
	node->u_data.branch.left = parse_tokens(tokens);
	node->u_data.branch.right = parse_tokens(right);
	return (node);
}

static t_list	*find_close(t_list *cur)
{
	int		depth;
	t_list	*prev;
	t_token	*token;

	depth = 1;
	prev = NULL;
	while (cur && depth)
	{
		token = (t_token *)cur->content;
		if (token->type == OP_OPEN_PARENTHESE)
			depth++;
		else if (token->type == OP_CLOSED_PARENTHESE)
			depth--;
		if (depth == 0)
			return (prev);
		prev = cur;
		cur = cur->next;
	}
	return (NULL);
}

t_tree	*new_subshell_branch(t_list *tokens)
{
	t_tree	*node;
	t_list	*close;
	t_list	*after;
	t_list	*inside;
	int		n_redirs;

	node = allocate_memory(sizeof(t_tree));
	inside = tokens->next;
	close = find_close(inside);
	after = close->next->next;
	close->next = NULL;
	node->type = SUBSHELL;
	node->u_data.subshell.child = parse_tokens(inside);
	n_redirs = count_redirs(after);
	node->u_data.subshell.n_redirs = n_redirs;
	node->u_data.subshell.redirs = extract_redirs(&after, n_redirs);
	return (node);
}
