/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:37:28 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/08 00:08:44 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

const char *operator_type_name(enum e_operator type) {
    switch (type) {
        case WORD:              return "WORD";
        case OP_OR:             return "OP_OR";
        case OP_AND:            return "OP_AND";
        case OP_APPEND:         return "OP_APPEND";
        case OP_HEREDOC:        return "OP_HEREDOC";
        case OP_REDIR_OUT:      return "OP_REDIR_OUT";
        case OP_REDIR_IN:       return "OP_REDIR_IN";
        case OP_OPEN_PARENTHESE:return "OP_OPEN_PARENTHESE";
        case OP_CLOSED_PARENTHESE:return "OP_CLOSED_PARENTHESE";
        case OP_PIPE:           return "OP_PIPE";
        case SUBSHELL:          return "SUBSHELL";
        case COMMAND:           return "COMMAND";
        default:                return "UNKNOWN";
    }
}

void print_tokens(t_list *list)
{
	if (!list) return;
    while (list) {
        t_token *token = (t_token *)list->content;
        printf("TOKEN___%s_______%s\n", token->value, operator_type_name(token->type));
        list = list->next;
    }
}

int	main(void)
{
	char		*cmd;
	t_list_info	*tokens;
	t_list		*list;
	t_token		*token;

	while (true)
	{
		cmd = readline("\e[32mnsh$\e[0m ");
		if (cmd && *cmd)
			add_history(cmd);
		tokens = tokenize(cmd);

		if (!tokens) continue;
		printf("\n-------tokenize-------\n\n");
		print_tokens(tokens->list);

		printf("\n-------TREE-------\n\n");
		if (!parse_check(tokens->list))
			continue;
        t_tree *root = parse_tokens(tokens->list);
        if (!root) continue;
        print_tree(root, 0);

		free(cmd);
	}
}
