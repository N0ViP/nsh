/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:21:44 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:24:34 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*try_path(char *dir, char *cmd, t_state *state)
{
	char	*full_path;

	full_path = join_two_strings(dir, cmd, "/");
	*state = path_validity(full_path);
	return (full_path);
}

char	*search_in_paths(char *cmd, char **paths, t_state *state)
{
	char	*full_path;
	char	*err_path;
	t_state	error;
	int		i;

	i = -1;
	err_path = NULL;
	error = NOT_FOUND_ERROR;
	while (paths[++i])
	{
		full_path = try_path(paths[i], cmd, state);
		if (*state == VALID_PATH)
		{
			return (full_path);
		}
		else if (!err_path && *state != NO_FILE_ERROR)
		{
			err_path = full_path;
			error = *state;
		}
	}
	*state = error;
	return (err_path);
}
