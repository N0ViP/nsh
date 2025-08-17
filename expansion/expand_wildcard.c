#include "expansion.h"

char	*join_words(t_info *info)
{
	t_list	*ptr;
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(info->len + 1);
	ptr = info->ex_word->list;
	i = 0;
	while (ptr)
	{
		j = 0;
		while (((char *)ptr->content)[j])
		{
			res[i] = ((char *)ptr->content)[j];
			i++;
			j++;
		}
		ptr = ptr->next;
	}
	res[i] = '\0';
	return (res);
}

void	expand_wildcard(t_info *info, t_list_info *arg_list)
{
	char	*word;
	t_list	*node;

	if (!info->ex_word->list)
	{
		return ;
	}
	word = join_words(info);
	// here we'll add wildcard
	node = creat_node(word);
	list_add_back(arg_list, node);
}
