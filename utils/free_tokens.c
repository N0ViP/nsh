/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:38:43 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:38:44 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*ptr;

	while (tokens)
	{
		ptr = tokens;
		tokens = tokens->next;
		free(ptr->word);
		free(ptr);
	}
}
