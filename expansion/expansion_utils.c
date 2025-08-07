#include "expansion.h"

void	utils(t_info *info, size_t i, size_t j, bool ex_wdc)
{
	char	*word;
	char	*tmp;

	add_in_wildcard_hashmap(info, ex_wdc);
	word = ft_substr(info->str, i, j);
	tmp = join_two_strings(info->word, word, "");
	info->word = tmp;
}
