#include "utils.h"

void	add_node_back(t_tokens **list, t_tokens *node)
{
	static t_tokens	*ptr;

	if (!*list)
	{
		*list = node;
		ptr = node;
		return ;
	}
	ptr->next = node;
	ptr = ptr->next;
}