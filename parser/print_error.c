/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:27:59 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 07:01:20 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

void	parse_error(const char *token)
{
	const char	*prefix;
	const char	*suffix;

	prefix = "syntax error near unexpected token `";
	suffix = "'\n";
	write(2, prefix, ft_strlen(prefix));
	write(2, token, ft_strlen(token));
	write(2, suffix, ft_strlen(suffix));
}
