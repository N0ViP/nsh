/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:41:01 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/02 03:41:15 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "nsh.h"
# include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;

t_list		*creat_node(void *content);
int			skip_spaces(char *str, int i);
char		*ft_substr(char *str, int i, int j);
void		add_node_back(t_list_info *list_info, t_list *node);
void		free_list(t_list_info **list_info, void (*free_content)());
#endif
