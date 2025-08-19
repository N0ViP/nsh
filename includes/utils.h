/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:41:01 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/18 05:27:54 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "nsh.h"

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;

t_list_info	    *init_list_info_struct();
enum e_operator check_token(char *token);
t_list			*creat_node(void *content);
size_t			skip_spaces(char *str, size_t i);
bool			check_if_match(char *sep, char c);
char			**lst_to_arr(t_list_info *list_info);
void			re_init_list_info_struct(t_list_info *list_info);
void			join_list(t_list_info *lst_1, t_list_info *lst_2);
void			list_add_back(t_list_info *list_info, t_list *node);
char			*join_list_content(t_list *list, char *del, size_t len);
char			*join_two_strings(char *s1, char *s2, char *delemiter);

#endif
