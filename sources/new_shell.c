#include "nsh.h"

bool init(void)
{
	static bool	init = false;

	if (init == false)
	{	
		shell_signals();
		update_cwd();
		env_setup();
		init = true;
	}
	return (init);
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
		_exit_status(UPDATE, 2);
		return (clean_before_prompt());
	}
    else
    {
        execute_tree(parse_in_tree(tokens));
		return (clean_before_prompt());
    }
}
