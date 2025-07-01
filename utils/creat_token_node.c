#include "utils.h"

t_tokens	*creat_token_node(char *token)
{
	t_tokens	*node;

	node = malloc(sizeof(t_tokens));
	if (!node)
	{
		return (NULL);
	}
	node->word = token;
	node->next = NULL;
	return (node);
}
