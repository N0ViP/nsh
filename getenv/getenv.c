# include "getenv.h"

t_list	*ft_getenv(int flag, char *var)
{
	static t_list	*env;
	static bool		init = true;

	if (init = true)
	{
		env = init_env();
		init = false;
	}
	if (flag == ADD_IN_ENV)
	{
		add_in_env(&env, var);
	}
	else if (flag == REMOVE_FROM_ENV)
	{
		remove_from_env(env, var);
	}
	return (env);
}
