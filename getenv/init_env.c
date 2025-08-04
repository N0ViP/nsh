# include "getenv.h"

static t_list	*split_env(char *str)
{
	char	*word;
	t_list	*val;

	val = malloc(sizeof(t_list));
	word = ft_strndup(str, ft_strlen(str));
	val->content = (void *)word;
	val->next = NULL;
	return (val);
}

t_list	*init_env()
{
	int		i;
	t_list	*val;
	t_list	*tail;
	t_list	*env;

	i = 0;
	if (!environ[0])
	{
		return (NULL);
	}
	env = split_env(environ[i++]);
	tail = env;
	while (environ[i])
	{
		val = split_env(environ[i]);
		tail->next = val;
		tail = val;
		i++;
	}
	return (env);
}
