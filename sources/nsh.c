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

int	main(void)
{
	t_list_info	*tokens;
	char		*cmd;

	while (true)
	{
		cmd = readline("\e[32mnsh$\e[0m ");
		if (cmd && *cmd)
			add_history(cmd);
		
		printf("\n-------tokenize-------\n\n");
		tokens = tokenize(cmd);
		if (!tokens) continue;
		print_tokens(tokens->list);

		printf("\n-------TREE-------\n\n");
		if (!parse_check(tokens->list)) continue;
        t_tree *root = parse_tokens(tokens->list);
        print_tree(root, 0);

		free(cmd);
	}
}
