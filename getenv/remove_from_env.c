# include "getenv.h"

static void	free_var_node(t_list *node)
{
	free(node->content);
	free(node);
}

static bool	check_and_remove(t_list *ptr, char *var)
{
	t_list	*tmp;

	if (!ft_strcmp_env(ptr->next->content, var))
	{
		tmp = ptr->next;
		ptr->next = ptr->next->next;
		free_var_node(tmp);
		return (true);
	}
	return (false);
}

void	remove_from_env(t_list_info *env, char *var)
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = env->list;
	if (!ptr)
		return ;
	if (!ft_strcmp_env(ptr->content, var))
	{
		tmp = env->list;
		env->list = env->list->next;
		free_var_node(tmp);
		env->size--;
		return ;
	}
	while (ptr->next)
	{
		if (check_and_remove(ptr, var))
		{
			env->size--;
			return ;
		}
		ptr = ptr->next;
	}
}
