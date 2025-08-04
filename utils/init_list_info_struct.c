# include "utils.h"

t_list_info	*init_list_info_struct()
{
	t_list_info	*token_info;

	token_info = malloc(sizeof(t_list_info));
	if (!token_info)
	{
		return (NULL);
	}
	token_info->list = NULL;
	token_info->tail = NULL;
	token_info->size = 0;
	return (token_info);
}