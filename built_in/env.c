#include "built-in.h"

static int	print_env(t_list *env_list)
{
	char		*equal;
	int			reval;

	while (env_list)
	{
		equal = ft_strchr(env_list->content, '=');
		if (equal)
		{
			reval = printf("declare -x %s\n", (char *)env_list->content);
		}
		if (reval == -1)
		{
			perror("env: write error");
			return (125);
		}
		env_list = env_list->next;
	}
	return (0);
}

int	built_in_env(char *args[])
{
	t_list_info	*env;
	int			exit_status;

	env = ft_getenv(GET_ENV, NULL);
	exit_status = print_env(env->list);
	return (exit_status);
}
