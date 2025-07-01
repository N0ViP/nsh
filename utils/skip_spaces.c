# include "utils.h"

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (ft_isspace(str[i + j]))
	{
		j++;
	}
	return (j);
}