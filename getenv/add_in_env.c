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

static t_list	*add_key_value(char *var)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->content = (void *)var;
	tmp->next = NULL;
	return (tmp);
}

void	add_in_env(t_list **env, char *var)
{
	t_list	*ptr;

	if (!*env)
	{
		*env = add_key_value(var);
		return ;
	}
	ptr = *env;
	if (check_modify_key(ptr, var))
	{
		return ;
	}
	while (ptr->next)
	{
		if (check_modify_key(ptr->next, var))
		{
			return ;
		}
		ptr = ptr->next;
	}
	if (!ptr->next)
	{
		ptr->next = add_key_value(var);
	}
}
