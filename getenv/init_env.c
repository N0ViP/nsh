# include "getenv.h"

static t_list	*dup_env_var(char *str)
{
	char	*word;
	t_list	*val;

	word = ft_strdup(str);;
	val = creat_node(word);
	return (val);
}

t_list_info	*init_env(void)
{
	int			i;
	t_list		*node;
	t_list_info	*env;

	i = 0;
	set_current_section(REMAINS);
	env = init_list_info_struct();
	while (environ[i])
	{
		node = dup_env_var(environ[i]);
		list_add_back(env, node);
		i++;
	}
	set_current_section(GLOBALE);
	return (env);
}
