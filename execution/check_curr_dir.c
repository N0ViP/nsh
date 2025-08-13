# include "execution.h"

bool check_state_and_curr_dir(char *cmd, char **full_path, t_state *state)
{
	char		*new_path;// exit code handle
	t_state		new_state;// is it for no cmd found or for no path found,
	if (*state == VALID_PATH)
		return (true);
	new_path = join_two_strings(".", cmd, "/");
	add_allocation_to_section(RESOLVE_PATH, new_path);
	new_state = path_validity(new_path);
	if (new_state == VALID_PATH)
	{
		*full_path = allocate_retval(EXECUTION, new_path);
		return (true);
	}
	else if (new_state != NO_FILE_ERROR)// should i change the state if no perm 
	{
		*state = new_state;
		*full_path = cmd;// cmd or new_path
	}
	return (false);
}
