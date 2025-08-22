/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:33 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:22 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

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

static int	print_env(t_list *env_list)
{
	char	*start;
	char	*equal;
	int		reval;

	while (env_list)
	{
		start = (char *)env_list->content;
		equal = ft_strchr(env_list->content, '=');
		if (equal)
		{
			reval = printf("declare -x %.*s\"%s\"\n", (int)(equal - start + 1),
					(char *)env_list->content, (char *)env_list->content
					+ (equal - start) + 1);
		}
		else
		{
			reval = printf("declare -x %s\n", (char *)env_list->content);
		}
		if (reval == -1)
			return (perror("nsh: export: write error"), 1);
		env_list = env_list->next;
	}
	return (0);
}

int	built_in_export(t_cmd *cmd_args)
{
	int			exit_status;
	char		**args;
	t_list_info	*env;
	size_t		i;

	i = 1;
	exit_status = 0;
	env = *env_list();
	args = cmd_args->args;
	if (!args[1])
		return (print_env(env->list));
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
