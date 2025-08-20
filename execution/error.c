# include "execution.h"

void exit_failure(char *msg)
{
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    perror(msg);
    exit_shell(EXIT_FAILURE);
}

bool return_failure(char *msg)
{
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    perror(msg);
    return (false);
}
