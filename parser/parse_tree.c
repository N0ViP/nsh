/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:53 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:27:54 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

t_tree	*parse_in_tree(t_list *tokens)
{
	t_tree	*root;

	set_current_section(GLOBALE);
	root = parse_tokens(tokens);
	destroy_section(TOKENIZE);
	return (root);
}
