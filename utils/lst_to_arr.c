#include "utils.h"

char	**lst_to_arr(t_list_info *list_info)
{
	size_t	i;
	char	**res;
	t_list	*lst;

	i = 0;
	lst = list_info->list;
	res = allocate_memory(sizeof(char *) * (list_info->size + 1));
	while (lst)
	{
		res[i] = lst->content;
		lst = lst->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
