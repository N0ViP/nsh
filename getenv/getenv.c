# include "getenv.h"

t_list_info	*ft_getenv(int flag, char *var)
{
	static t_list_info	*env;
	static bool			init = true;
	char				*dup_var;

	if (var)
	{
		dup_var = allocate_retval(ENVIRON, var);
	}
	if (init == true)
	{
		env = init_env();
		init = false;
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
