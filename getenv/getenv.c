# include "getenv.h"

t_list_info	**env_list(void)
{
	static t_list_info	*env = NULL;
	return (&env);
}

void env_setup(void)
{
	t_list_info		**env;

	env = env_list();
	*env = init_env();
}

t_list_info	*ft_getenv(int flag, char *var)
{
	t_list_info		*env;
	char			*dup_var;
	
	env = *env_list();
	if (var)
	{
		dup_var = allocate_retval(ENVIRON, var);
	}
	if (flag == ADD_IN_ENV)
	{
		add_in_env(env, dup_var);
	}
	else if (flag == REMOVE_FROM_ENV)
	{
		remove_from_env(env, dup_var);
	}
	return (env);
}
