#ifndef EXPANSION_H
# define EXPANSION_H

# include "nsh.h"
# include "getenv.h"
# include "utils.h"

typedef struct s_expander_vars
{
	char	*str;
	char	*word;
	char	*hashmap;
	size_t	wildcard;
}	t_info;

bool	check_if_dollar(char *str);
bool	regular_word_checker(char *str);
bool	double_quotes_checker(char *str);
size_t	expand_single_quote_word(t_info *info);
void	expand_wildcard(char **word, char **hashmap);
void	utils(t_info *info, size_t i, size_t j, bool wildcard_falg);
size_t	expand_double_quotes_word(char *s, char **arg, char **hashmap);
void	add_in_wildcard_hashmap(char **hashmap, size_t wildcard, bool expand);
size_t	expand_dollar_word(t_info *info, t_list_info *arg_list, bool rm_spaces);
size_t	expand_regular_word(t_info *info, bool (*checker)(char *), bool ex_wdc);

#endif
