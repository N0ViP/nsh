#include "built-in.h"

bool go_home(void)
{
	char *home;

	home = get_var_value("OLDPWD");
	if (!home)
	{
		print_cd_error(NULL, "HOME not set");
        return (false);
	}
	if (chdir(home) == -1)
	{
		print_cd_error(home, strerror(errno));
		return (false);
	}
	update_oldpwd();
	if (!update_pwd())//should it print error or update with path
	{
		print_cd_error("getcwd", strerror(errno));//whats the error
		return (false);
	}
	return (true);
}

bool go_old_pwd(void)
{
	char *oldpwd;

	oldpwd = get_var_value("OLDPWD");
	if (!oldpwd)
	{
		print_cd_error(NULL, "OLDPWD not set");
        return (false);
	}
	if (chdir(oldpwd) == -1)
	{
		print_cd_error(oldpwd, strerror(errno));
		return (false);
	}
	update_oldpwd();
	if (!update_pwd())//should it print error or update with path
	{
		print_cd_error("getcwd", strerror(errno));//whats the error
		return (false);
	}
	write(STDERR_FILENO, oldpwd, ft_strlen(oldpwd));
	write(STDERR_FILENO, "\n", 1);
	return (true);
}

bool go_to_path(char *path)
{
    
    if (chdir(path) == -1)
    {
        print_cd_error(path, strerror(errno));
        return (false);
    }
	update_oldpwd();
    if (!update_pwd())//should it print error or update with path
    {
        print_cd_error("getcwd", strerror(errno));//
        return (false);
    }
	return (true);
}
