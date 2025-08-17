#include "built-in.h"

static void print_cd_error(char *path, char *error)
{
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": cd: ", 6);
    if (path)
	{
        write(STDERR_FILENO, path, ft_strlen(path));
		write(STDERR_FILENO, ": ", 2);
	}
    if (error)
	{
		write(STDERR_FILENO, error, ft_strlen(error));
		write(STDERR_FILENO, "\n", 1);
	}
}

static void update_oldpwd(void)
{
    char *pwd;

    pwd = get_var_value("PWD");
    if (pwd)
    {
		add_allocation_to_section(EXECUTION, pwd);
        set_var_value("OLDPWD", pwd);
    }
}

static bool update_pwd(void)
{
    char *cwd;

    cwd = update_cwd();//what if it fail
    if (cwd)
	{
		set_var_value("PWD", cwd);
		free(cwd);	
		return (true);
    }
	return (false);
}

static bool go_home(void)
{
	char *home;

	home = get_var_value("OLDPWD");
	if (!home)
	{
		print_cd_error(NULL, "HOME not set");
        return (false);
	}
	add_allocation_to_section(EXECUTION, home);
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

static bool go_old_pwd(void)
{
	char *oldpwd;

	oldpwd = get_var_value("OLDPWD");
	if (!oldpwd)
	{
		print_cd_error(NULL, "OLDPWD not set");
        return (false);
	}
	add_allocation_to_section(EXECUTION, oldpwd);
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

static bool go_to_path(char *path)
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

int built_in_cd(char **path)
{
    path++;
    if (!(*path))
    {
		if (!go_home())
			return (EXIT_FAILURE);
    }
    else if (!ft_strcmp(*path, "-"))
    {
        if (!go_old_pwd())
			return (EXIT_FAILURE);
    }
	else
	{
        if (!go_to_path(*path))
			return (EXIT_FAILURE);
	}
    return (EXIT_SUCCESS);
}
