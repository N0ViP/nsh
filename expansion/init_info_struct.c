#include "expansion.h"

void	init_info_struct(t_info *info, char *str)
{
	info->len = 0;
	info->str = str;
	info->hashmap = add_in_wildcard_hashmap(0, RESET_OFFSET, false);
	info->ex_word = init_list_info_struct();
}
