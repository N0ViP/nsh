#include "expansion.h"

static void	reset_wildcard(size_t star_index)
{
	size_t	i;

	i = 0;
	wildcard_offset(RESET_OFFSET);
	while (i <= star_index)
	{
		wildcard_offset(NEXT_OFFSET);
		i++;
	}
}

static bool	handle_star(char **pattern, char *word,
		char **star, size_t *star_index)
{
	*star = *pattern;
	(*pattern)++;
	*star_index = wildcard_offset(CURR_OFFSET);
	wildcard_offset(NEXT_OFFSET);
	(void)word;
	return (true);
}

static bool	process_word(char **pattern, char **word,
		char **star, size_t *star_index, char **backup, bool *hashmap)
{
	if (**pattern == **word)
	{
		if (*(*pattern)++ == '*')
			wildcard_offset(NEXT_OFFSET);
		(*word)++;
		return (true);
	}
	if (**pattern == '*' && hashmap[wildcard_offset(CURR_OFFSET)])
	{
		handle_star(pattern, *word, star, star_index);
		*backup = *word;
		return (true);
	}
	if (*star)
	{
		*pattern = *star + 1;
		reset_wildcard(*star_index);
		*word = ++(*backup);
		return (true);
	}
	return (false);
}

static bool	check_remaining(char *pattern, bool *hashmap)
{
	while (*pattern)
	{
		if (*pattern != '*' || !hashmap[wildcard_offset(CURR_OFFSET)])
			return (false);
		wildcard_offset(NEXT_OFFSET);
		pattern++;
	}
	return (true);
}

bool	wildcard_match(char *pattern, char *word, bool *hashmap)
{
	char	*star;
	char	*backup;
	size_t	star_index;

	star = NULL;
	backup = NULL;
	star_index = 0;
	while (*word)
	{
		if (!process_word(&pattern, &word, &star,
				&star_index, &backup, hashmap))
			return (false);
	}
	return (check_remaining(pattern, hashmap));
}
