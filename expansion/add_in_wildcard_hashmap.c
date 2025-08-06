#include "expansion.h"

void	add_in_wildcard_hashmap(t_info *info, size_t wildcard, bool expand)
{
	static size_t	k;
	static size_t	i;
	char			*tmp;

	if (!info->hashmap)
	{
		k = ARENA_SIZE;
		i = 0;
		info->hashmap = malloc(k);
	}
	while (i + wildcard > k)
	{
		k += ARENA_SIZE;
		tmp = ft_realloc(info->hashmap, k - ARENA_SIZE, k);
		info->hashmap = tmp;
	}
	while (wildcard--)
	{
		info->hashmap[i++] = expand;
	}
}
