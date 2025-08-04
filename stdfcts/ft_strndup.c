# include "stdfcts.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;
	
	i = 0;
	dup = malloc(n + 1);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
