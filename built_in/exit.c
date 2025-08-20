#include "built-in.h"

static int	process_exit(char **argv, int n_arg)
{
	long long exit_code;

    write(STDERR_FILENO, "exit\n", 5);
    if (n_arg > 1)
    {
        exit_code = 0;
        if (!arg_to_exit_code(argv[1], &exit_code))
        {
            print_exit_error(" numeric argument required\n", argv[1]);
            exit_shell(255);
        }
        if (n_arg > 2)
        {
            print_exit_error("too many arguments\n", NULL);
            return (EXIT_FAILURE);
        }
        exit_shell((unsigned char)exit_code);
    }
    exit_shell(_exit_status(EXTRACT, 0) & 0b11111111);
	return (EXIT_SUCCESS);
}

int built_in_exit(t_cmd *cmd_args)
{
    char   **argv;
    int    n_arg;

    argv = cmd_args->args;
    n_arg = cmd_args->n_arg;
    if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
        exit_shell(_exit_status(EXTRACT, 0) & 0b11111111);
    return (process_exit(argv, n_arg));
}