#include "utils.h"

void	re_init_list_info_struct(t_list_info *list_info)
{
	list_info->list = NULL;
	list_info->tail = NULL;
	list_info->size = 0;
}