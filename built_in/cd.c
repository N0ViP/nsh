// #include "built-in.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void	built_in_cd(char **args)
{
	if (!args[0] || args[1])
	{
		write(2, "nsh: cd: wrong arguments\n", 25);
		return ;
	}
	if (chdir(*args) == -1 && errno == EACCES)
		write(2, "cd: Permission denied\n", 22);
}

// int main()
// {
// 	char *av[] = {"/", NULL};
// 	printf("%s\n", getcwd(NULL, 0));
// 	built_in_cd(av);
// 	printf("%s\n", getcwd(NULL, 0));
// }
