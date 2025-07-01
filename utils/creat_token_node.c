/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_token_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:38:17 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:38:19 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_tokens	*creat_token_node(char *token)
{
	t_tokens	*node;

	node = malloc(sizeof(t_tokens));
	if (!node)
	{
		return (NULL);
	}
	node->word = token;
	node->next = NULL;
	return (node);
}
