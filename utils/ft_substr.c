#include "utils.h"

char	*ft_substr(char *cmd, int i, int j)
{
	char	*res;
	int		k;
	
	k = 0;
	res = malloc(j - i + 1);
	if (!res)
	{
		return (NULL);
	}
	while (i < j)
	{
		res[k] = cmd[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}
