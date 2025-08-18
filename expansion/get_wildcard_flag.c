#include "expansion.h"

bool	get_wildcard_flag(t_info *info)
{
	static size_t	i;

	return ((bool) info->hashmap[i++]);
}
