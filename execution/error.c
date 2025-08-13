# include "execution.h"

void exit_failure(char *msg)
{
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": ", 2);
    perror(msg);
    exit(EXIT_FAILURE);
}
