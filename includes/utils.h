/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:41:01 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:41:03 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "nsh.h"

int			skip_spaces(char *str, int i);
char		*ft_substr(char *cmd, int i, int j);
void		add_node_back(t_tokens **list, t_tokens *node);

#endif
