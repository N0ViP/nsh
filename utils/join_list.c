#include "utils.h"

void	join_list(t_list_info *lst_1, t_list_info *lst_2)
{
	if (!lst_1->list)
	{
		lst_1->list = lst_2->list;
	}
	else
	{
		lst_1->tail->next = lst_2->list;
	}
	lst_1->tail = lst_2->tail;
	lst_1->size += lst_2->size;
}