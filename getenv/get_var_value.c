#include "getenv.h"

static char	*split_val_from_key(char *var)
{
	char	*value;
	size_t	i;

	i = 0;
	while (var[i] != '\0' && var[i] != '=')
	{
		i++;
	}
	if (var[i] == '\0' || var[i + 1] == '\0')
	{
		return (NULL);
	}
	value = ft_substr(var, i + 1, ft_strlen(var) - 1);
}

char	*get_var_value(char *var)
{
	t_list	*env;
	char	*value;

	env = ft_getenv(GET_ENV, NULL);
	while (env)
	{
		if (!ft_strcmp_env(env->content, var))
		{
			value = split_val_from_key(env->content);
			return (value);
		}
		env = env->next;
	}
	return (NULL);
}