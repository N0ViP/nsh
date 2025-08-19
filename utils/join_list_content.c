#include "utils.h"

char	*join_list_content(t_list *list, char *del, size_t len)
{
	char	*str;
	size_t	i;
	size_t	tmp_node_len;
	size_t	tmp_del_len;

	i = 0;
	str = allocate_memory(len + 1);
	tmp_del_len = ft_strlen(del);
	while (list)
	{
		tmp_node_len = ft_strlen(list->content);
		ft_memcpy(str + i, list->content, tmp_node_len);
		i += tmp_node_len;
		list = list->next;
		if (*del && list && *(char *)list->content)
		{
			ft_memcpy(str + i, del, tmp_del_len);
			i += tmp_del_len;
		}
	}
	str[i] = '\0';
	return (str);
}
