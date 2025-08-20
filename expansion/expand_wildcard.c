#include "expansion.h"

void	expand_wildcard(t_info *info, t_list_info *arg_list)
{
	char	*word;
	t_list	*node;

	if (!info->ex_word->list)
	{
		return ;
	}
	word = join_list_content(info->ex_word->list, "", info->len);
	// here we'll add wildcard
	node = creat_node(word);
	list_add_back(arg_list, node);
	info->hashmap = NULL;
	wildcard_offset(RESET_OFFSET);
}
