#include "expansion.h"

void	expand_wildcard(t_info *info, t_list_info *arg_list)
{
	t_list		*node;

	if (!info->word)
	{
		return ;
	}
	node = creat_node(info->word);
	list_add_back(arg_list, node);
}
