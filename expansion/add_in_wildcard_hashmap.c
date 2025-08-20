#include "expansion.h"

bool	*add_in_wildcard_hashmap(size_t wildcard, int flag, bool ex_wdc)
{
	static size_t	cap;
	static size_t	i;
	static bool		*hashmap;

	if (flag == RESET_OFFSET)
	{
		i = 0;
	}
	if (!hashmap)
	{
		cap = INITIAL_CAPACITY;
		hashmap = new_allocation(REMAINS, cap * sizeof(bool));
	}
	if (cap < i + wildcard)
	{
		while (cap < i + wildcard)
			cap *= 2;
		hashmap = ft_realloc(hashmap, i * sizeof(bool), cap * sizeof(bool));
	}
	while (wildcard--)
	{
		hashmap[i++] = ex_wdc;
	}
	return (hashmap);
}
