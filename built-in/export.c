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

int	built_in_export(char **args)
{
	size_t	i;
	int		exit_status;

	i = 0;
	exit_status = 0;
	if (!args[1])
	{
		print_env();
	}
	else
	{
		if (check_name(args[1]))
		{
			ft_getenv(ADD_IN_ENV, args[1]);
		}
		else
		{
			syntax_error(args[1]);
			exit_status = 1;
		}
	}
	return (exit_status);
}
