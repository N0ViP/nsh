# include "utils.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*ptr;

	while (tokens)
	{
		ptr = tokens;
		tokens = tokens->next;
		free(ptr->word);
		free(ptr);
	}
}