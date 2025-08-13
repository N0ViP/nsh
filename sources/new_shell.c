#include "nsh.h"

bool	read_command(char **cmd)
{
	*cmd = readline("\e[32mnsh$\e[0m ");
	if (!*cmd)
    {
		exit(0);
    }
	else if (!**cmd)
	{
		free(*cmd);
		return (false);
	}
	add_history(*cmd);
	return (true);
}

void	new_shell(char *cmd)
{
	t_list	*tokens;

	tokens = tokenize(cmd);
	if (!tokens)
    {
		return (clean_before_prompt());
    }
	else if (!parse_check(tokens))
	{
		_exit_status(SAVE_VALUE, 2);
		return (clean_before_prompt());
	}
    else
    {
        execute_tree(parse_in_tree(tokens));
		return (clean_before_prompt());
    }
}
