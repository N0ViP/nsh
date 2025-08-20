#include "expansion.h"

void	add_in_wildcard_hashmap(t_info *info, bool ex_wdc)
{
	static size_t	k;
	static size_t	i;
	bool			*new_hashmap;

	if (!info->hashmap)
	{
		k = INITIAL_CAPACITY;
		i = 0;
		info->hashmap = allocate_memory(k * sizeof(bool));
	}
	if (k < i + info->wildcard)
	{
		while (k < i + info->wildcard)
		{
			k *= 2;
		}
		new_hashmap = ft_realloc(info->hashmap, i * sizeof(bool), k * sizeof(bool));
		info->hashmap = new_hashmap;
	}
	while (info->wildcard--)
	{
		info->hashmap[i++] = ex_wdc;
	}
}
