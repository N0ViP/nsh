# include "execution.h"

static char *try_path(char *dir, char *cmd, t_state *state)
{
    char *full_path;
	
	full_path = join_two_strings(dir, cmd, "/");
    add_allocation_to_section(RESOLVE_PATH, full_path);
    *state = path_validity(full_path);
    return (full_path);
}

char *search_in_paths(char *cmd, char **paths, t_state *state)
{
	char		*full_path;
	char		*err_path;
	t_state		error;
	int			i;

	i = -1;
    err_path = NULL;
	error = NOT_FOUND_ERROR;
    while (paths[++i])
	{
        full_path = try_path(paths[i], cmd, state);
		if (*state == VALID_PATH)//first that works
		{
		    return (full_path);
		}
		else if (!err_path && *state != NO_FILE_ERROR)
		{						//first err even if not perm err
			err_path = full_path;
			error = *state;
		}
    }
	*state = error;
    return (err_path);
}
