#include "expansion.h"

char	*join_two_strings(char *s1, char *s2, char *delemiter)
{
	char	*arr[3];
	char	*join;

	arr[0] = s1;
	arr[1] = s2;
	arr[2] = NULL;
	join = ft_strjoin(arr, delemiter);
}