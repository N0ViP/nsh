#include "built-in.h"

char **shell_cwd(void)
{
	static char	*cwd = NULL;
	return (&cwd);
}

char *update_cwd(void)
{
	char *new_cwd;
	char **old_cwd;

    old_cwd = shell_cwd();
	new_cwd = getcwd(NULL, 0);
	add_allocation_to_section(REMAINS, new_cwd);
    *old_cwd = new_cwd;
    return (*old_cwd);
}

void update_oldpwd(void)
{
    char *pwd;

    pwd = get_var_value("PWD");
    if (pwd)
    {
        set_var_value("OLDPWD", pwd);
    }
}

bool update_pwd(void)
{
    char *cwd;

    cwd = update_cwd();
    if (cwd)
	{
		set_var_value("PWD", cwd);
		return (true);
    }
	return (false);
}
