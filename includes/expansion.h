#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"
# include "getenv.h"
# include "utils.h"

bool	check_if_dollar(char *str);
size_t	expand_regular_word(char *s, char **arg, char **hashmap);
size_t	expand_single_quote_word(char *s, char **arg, char **hashmap);
size_t	expand_double_quotes_word(char *s, char **arg, char **hashmap);
void	add_in_wildcard_hashmap(char **hashmap, size_t wildcard, bool expand);
size_t	expand_dollar_word(char *s, char **arg, char **hashmap, bool rm_spaces);

#endif
