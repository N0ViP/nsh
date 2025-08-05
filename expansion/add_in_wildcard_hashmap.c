#include "expansion.h"

void	add_in_wildcard_hashmap(char **hashmap, size_t wildcard, bool expand)
{
	static size_t	k;
	static size_t	i;

	if (!*hashmap)
	{
		k = ARENA_SIZE;
		i = 0;
		*hashmap = malloc(k);
	}
	while (i + wildcard > k)
	{
		k += ARENA_SIZE;
		*hashmap = ft_realloc(hashmap, k - ARENA_SIZE, k);
	}
	while (wildcard--)
	{
		(*hashmap)[i++] = expand;
	}
}
