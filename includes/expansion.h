#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"

typedef struct s_expander_vars
{
	t_list_info	*ex_word;
	char		*str;
	char		*hashmap;
	size_t		len;
	size_t		wildcard;
}	t_info;

# define CURR_OFFSET	0
# define NEXT_OFFSET	1
# define PREV_OFFSET	2
# define RESET_OFFSET	3


t_list_info *expander(char *str);
size_t		wildcard_offset(int flag);
bool		check_if_dollar(char *str);
bool		get_wildcard_flag(t_info *info);
bool		regular_word_checker(char *str);
bool		expand_cmd_args(t_tree *branch);
bool 		expand_filenames(t_tree *branch);
bool		double_quotes_checker(char *str);
size_t		expand_single_quote_word(t_info *info);
size_t		expand_double_quotes_word(t_info *info);
void		add_in_wildcard_hashmap(t_info *info, bool ex_wdc);
void		expand_wildcard(t_info *info, t_list_info *arg_list);
void		utils(t_info *info, size_t i, size_t j, bool ex_wdc);
size_t		expand_dollar_word(t_info *info, t_list_info *arg_list, bool rm_spaces);
size_t		expand_regular_word(t_info *info, bool (*checker)(char *), bool ex_wdc);

#endif
