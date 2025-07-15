#include "stdfcts.h"

int	count_words(const char *s, char c)
{
	int count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return count;
}

static char	*ft_strndup(const char *s, size_t n)
{
	char *dup = malloc(n + 1);
	size_t i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return dup;
}

static void	cleanup(char **result, int i)
{
	while (i-- > 0)
		free(result[i]);
	free(result);
}

char	**ft_split(const char *s, char c)
{
	if (!s)
		return NULL;
	int word_count = count_words(s, c);
	char **result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return NULL;
	int i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		int word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		result[i] = ft_strndup(s, word_len);
		if (!result[i])
		{
			cleanup(result, i);
			return NULL;
		}
		s += word_len;
		i++;
	}
	result[i] = NULL;
	return result;
}
