# include "getenv.h"

static void	free_var_node(t_list *ptr)
{
	free(ptr->content);
	free(ptr);
}

void	remove_from_env(t_list **env, char *var)
{
	t_list	*ptr;
	t_list	*tmp;

	if (!*env)
		return ;
	ptr = *env;
	if (!ft_strcmp_env(ptr->content, var))
	{
		*env = ptr->next;
		free_var_node(ptr);
		return ;
	}
	while (ptr->next)
	{
		if (!ft_strcmp(ptr->next->content, var))
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			free_var_node(tmp);
			return ;
		}
		ptr = ptr->next;
	}
}
