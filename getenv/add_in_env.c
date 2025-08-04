#include "getenv.h"

static bool	check_modify_key(t_list *ptr, char *var)
{
	if (!ft_strcmp_env(ptr->content, var))
	{
		free(ptr->content);
		ptr->content = var;
		return (true);
	}
	return (false);
}

void	add_in_env(t_list_info *env, char *var)
{
	t_list	*ptr;
	t_list	*node;

	ptr = env->list;
	while (ptr)
	{
		if (check_modify_key(ptr, var))
		{
			return ;
		}
		ptr = ptr->next;
	}
	node = creat_node(var);
	list_add_back(env, node);
}
