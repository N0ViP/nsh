#include "expansion.h"

void	add_in_wildcard_hashmap(t_info *info, bool ex_wdc)
{
	static size_t	k;
	static size_t	i;
	char			*tmp;

	if (!info->hashmap)
	{
		k = ARENA_SIZE;
		i = 0;
		info->hashmap = allocate_memory(k * sizeof(bool));
	}
	while (i + info->wildcard > k)
	{
		k += ARENA_SIZE;
		tmp = ft_realloc(info->hashmap, (k - ARENA_SIZE) * sizeof(bool), k * sizeof(bool));
		info->hashmap = tmp;
	}
	while (info->wildcard--)
	{
		info->hashmap[i] = ex_wdc;
		i++;
	}
}
