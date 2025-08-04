#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"
# include "getenv.h"
# include "utils.h"

bool	check_if_dollar(char *str);
size_t	expand_regular_word(char *str, t_list_info *value);
size_t	expand_single_quote_word(char *str, t_list_info *value);
size_t	expand_double_quote_word(char *str, t_list_info *value);
size_t	expand_dollar_word(char *str, t_list_info *value, bool remove_spaces);

#endif
