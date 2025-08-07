/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:41:01 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/06 22:49:15 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "nsh.h"
# include "stdbool.h"
# include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;

void            _free(char **str);
t_list_info	    *init_list_info_struct();
enum e_operator	check_token(char *token);
t_list			*creat_node(void *content);
int				skip_spaces(char *str, size_t i);
bool			check_if_match(char *sep, char c);
void			list_add_back(t_list_info *list_info, t_list *node);
char			*join_two_strings(char *s1, char *s2, char *delemiter);
void			free_list(t_list_info **list_info, void (*free_content)());

#endif
