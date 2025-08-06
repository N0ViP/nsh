#include "expansion.h"

void	expand_wildcard(char **word, char **hashmap)
{
	char	**splited_words;
	char	**splited_spaces;

	splited_words = ft_split(*word, " \t\n", false);
	splited_spaces = ft_split(*word, " \t\n", true);
}