/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iam_a_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:35 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:24 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

bool	iam_a_child(int flag)
{
	static bool	state = false;

	if (flag == UPDATE)
	{
		state = true;
	}
	return (state);
}
