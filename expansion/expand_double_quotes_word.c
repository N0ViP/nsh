#include "expansion.h"

int	expand_double_quote_word(char *str, t_list_info *value)
{
	char	*word;
	t_list	*node;
	bool	dollar;
	int		n;

	n = 1;
	dollar = false;
	if (str[0] != '"')
	{
		retrun (0);
	}
	while (str[n] != '\0' && str[n] != '"')
	{
		// same logic like as expand (reg_word, sin_word, dollar_word,...)
		n++;
	}
	return (n + 1);
}
