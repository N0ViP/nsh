#include "built-in.h"

static void	syntax_error(char *str)
{
	char	*arr[4];
	char	*message;

	arr[0] = "nsh: export: `";
	arr[1] = str;
	arr[2] = "': not a valid identifier\n";
	arr[3] = NULL;
	message = ft_strjoin(arr, "");
	write(2, message, ft_strlen(message));
}

static bool	check_name(char *str)
{
	size_t	i;

	i = 0;
	if (!ft_isalpha(str[0]))
	{
		return (false);
	}
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static int	print_env(void)
{
	t_list_info	*env;
	t_list		*ptr;
	char		*start;
	char		*equal;

	env = ft_getenv(GET_ENV, NULL);
	ptr = env->list;
	while (ptr)
	{
		start = (char *)ptr->content;
		equal = ft_strchr(ptr->content, '=');
		if (equal)
		{
			printf("declare -x %.*s\"%s\"\n", (int)(equal - start + 1), ptr->content, ptr->content + (equal - start) + 1);
		}
		else
		{
			printf("declare -x %s\n", (char *)ptr->content);
		}
		ptr = ptr->next;
	}
}

int	built_in_export(char **args)
{
	size_t	i;
	int		exit_status;

	i = 1;
	exit_status = 0;
	if (!args[1])
	{
		exit_status = print_env();
		return (exit_status);
	}
	while (args[i])
	{
		if (check_name(args[i]))
		{
			ft_getenv(ADD_IN_ENV, args[i]);
		}
		else
		{
			syntax_error(args[i]);
			exit_status = 1;
		}
		i++;
	}
	return (exit_status);
}
