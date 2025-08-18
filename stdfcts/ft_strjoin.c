#include "stdfcts.h"

static size_t	ft_words_len(char **arr, size_t delemiter_len)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			j++;
		}
		len += j;
		i++;
		if (arr[i])
		{
			len += delemiter_len;
		}
	}
	return (len);
}

static void	fill_str(char **arr, char *delemiter, char *str)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_strcat(str, arr[i]);
		i++;
		if (delemiter && arr[i])
		{
			ft_strcat(str, delemiter);
		}
	}
}

char	*ft_strjoin(char **arr, char *delemiter)
{
	size_t	words_len;
	size_t	delemiter_len;
	char	*str;

	delemiter_len = ft_strlen(delemiter);
	words_len = ft_words_len(arr, delemiter_len);
	str = smalloc(words_len + 1);
	str[0] = '\0';
	fill_str(arr, delemiter, str);
	return (str);
}
