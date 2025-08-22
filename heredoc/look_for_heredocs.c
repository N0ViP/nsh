/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:24:46 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:55:43 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

bool	look_for_heredocs(t_tree *root)
{
	if (!root)
		return (true);
	if (root->type == COMMAND)
	{
		if (process_heredocs(root) == 130)
			return (false);
		return (true);
	}
	else if (root->type == SUBSHELL)
	{
		if (process_heredocs(root) == 130)
			return (false);
		if (!look_for_heredocs(root->u_data.subshell.child))
			return (false);
		return (true);
	}
	if (!look_for_heredocs(root->u_data.branch.left))
		return (false);
	if (!look_for_heredocs(root->u_data.branch.right))
		return (false);
	return (true);
}
