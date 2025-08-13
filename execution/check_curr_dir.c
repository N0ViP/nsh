# include "execution.h"

char *check_and_curr_dir(char *cmd)
{
	char		*cmd_path;
	t_state		state;

	cmd_path = join_two_strings(".", cmd, "/");
	add_allocation_to_section(EXECUTION, cmd_path);
	state = path_validity(cmd_path);
	if (state == VALID_PATH)
	{
		return (cmd_path);
	}
	else
	{
		cmd = allocate_retval(EXECUTION, cmd);
	}
	return (report_error(cmd, state), NULL);
}
