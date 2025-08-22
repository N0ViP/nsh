/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:26:32 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:31:52 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"

typedef struct s_expander_vars
{
	t_list_info	*ex_word;
	bool		*hashmap;
	char		*str;
	size_t		len;
	size_t		wildcard;
}				t_info;

# define CURR_OFFSET	0
# define NEXT_OFFSET	1
# define PREV_OFFSET	2
# define RESET_OFFSET	3

void			init_hashmap(void);
t_list_info		*expander(char *str);
size_t			wildcard_offset(int flag);
bool			check_if_dollar(char *str);
bool			get_wildcard_flag(t_info *info);
bool			regular_word_checker(char *str);
bool			expand_cmd_args(t_tree *branch);
bool			expand_filenames(t_tree *branch);
bool			double_quotes_checker(char *str);
size_t			expand_single_quote_word(t_info *info);
size_t			expand_double_quotes_word(t_info *info);
void			init_info_struct(t_info *info, char *str);
void			process_arg(t_info *info, t_list_info *arg_list);
void			utils(t_info *info, size_t i, size_t j, bool ex_wdc);
bool			*add_in_wildcard_hashmap(size_t wildcard, int flag,
					bool ex_wdc);
size_t			expand_dollar_word(t_info *info, t_list_info *arg_list,
					bool rm_spaces);
size_t			expand_regular_word(t_info *info, bool (*checker)(char *),
					bool ex_wdc);
void			process_and_split_value(t_info *info, t_list_info *arg_list,
					char *val, char **splited_val);

#endif
