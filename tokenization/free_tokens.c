#include "tokenization.h"

void	free_tokens(t_list *node)
{
	free(node->content);
	node->content = NULL;
}