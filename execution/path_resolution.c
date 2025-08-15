# include "execution.h"

static char *cmd_with_path(char *cmd)
{
	t_state		state;

	state = path_validity(cmd);
	if (state == VALID_PATH)
	{
		return (allocate_retval(EXECUTION, cmd));
	}
	return (report_error(cmd, state), NULL);
}

static char *find_in_paths(char *cmd, char **paths, t_state *state)
{
    char *ret_cmd;

	ret_cmd = search_in_paths(cmd, paths, state);
    if (ret_cmd && (*state == VALID_PATH || *state != NOT_FOUND_ERROR))
	{				//only if perm error or rm *state == PERMISSION_ERROR??
        return (allocate_retval(EXECUTION, ret_cmd));
	}
	return (allocate_retval(EXECUTION, cmd));
}

char	*path_resolution(char *cmd)
{
	t_state		state;
	char		**paths;
	char		*path_env;
	char		*full_path;

	if (ft_strchr(cmd, '/'))
		return (cmd_with_path(cmd));
	path_env = get_var_value("PATH");
	if (!path_env || !*path_env)
		return (check_and_curr_dir(cmd));
	add_allocation_to_section(RESOLVE_PATH, path_env);
	paths = ft_split(path_env, ":");
	add_allocations_to_section(RESOLVE_PATH, (void **)paths);
	full_path = find_in_paths(cmd, paths, &state);
	// destroy_section(RESOLVE_PATH);
	if (state != VALID_PATH)
		report_error(full_path, state);
	return (full_path);
}
