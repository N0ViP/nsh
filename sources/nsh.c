/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:37:28 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/02 03:40:04 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

int	main(void)
{
	char		*cmd;
	t_list_info	*tokens;
	t_list *list;

	while (true)
	{
		cmd = readline("\e[32mnsh$\e[0m ");
		if (cmd && *cmd)
			add_history(cmd);
		tokens = tokenize(cmd);
		if (!tokens)
			return (1);
		list = tokens->list;
		while (list)
		{
			printf("%s\n", (t_token *)(list->content)->value);
			list = list->next;
		}
	}
}
