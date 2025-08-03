#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"
# include "getenv.h"

size_t	expand_regular_word(char *str, t_list_info *value);
size_t	expand_dollar_word(char *str, t_list_info *value);
size_t	expand_single_quote_word(char *str, t_list_info *value);


#endif
