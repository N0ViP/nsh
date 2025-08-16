#include "expansion.h"

void	utils(t_info *info, size_t i, size_t j, bool ex_wdc)
{
	t_list	*node;
	char	*word;

	(void)ex_wdc;
	// add_in_wildcard_hashmap(info, ex_wdc);
	word = ft_substr(info->str, i, j);
	node = creat_node(word);
	list_add_back(info->ex_word, node);
	info->len += j - i;
}
