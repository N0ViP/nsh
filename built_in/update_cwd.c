/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:48 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:44:31 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

char	**shell_cwd(void)
{
	static char	*cwd = NULL;

	return (&cwd);
}

char	*update_cwd(void)
{
	char	*new_cwd;
	char	**old_cwd;

	old_cwd = shell_cwd();
	new_cwd = getcwd(NULL, 0);
	if (!new_cwd)
		return (NULL);
	set_current_section(REMAINS);
	*old_cwd = ft_strdup(new_cwd);
	set_current_section(GLOBALE);
	free(new_cwd);
	return (*old_cwd);
}

void	update_oldpwd(void)
{
	char	*pwd;

	pwd = get_var_value("PWD");
	if (pwd)
	{
		set_var_value("OLDPWD", pwd);
	}
}

bool	update_pwd(void)
{
	char	*cwd;

	cwd = update_cwd();
	if (cwd)
	{
		set_var_value("PWD", cwd);
		return (true);
	}
	return (false);
}
