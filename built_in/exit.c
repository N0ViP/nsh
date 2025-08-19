#include "built-in.h"

static void print_exit_error(char *error, char *arg)
{
    write(STDERR_FILENO, SHELL, ft_strlen(SHELL));
    write(STDERR_FILENO, ": exit: ", 8);
    if (arg)
        write(STDERR_FILENO, arg, ft_strlen(arg));
    write(STDERR_FILENO, error, ft_strlen(error));
}

static bool convert_to_num(char *str, int sign, long long *exit_code)
{
    unsigned long long    number;
    unsigned long long    limit;
    unsigned long long    digit;

    number = 0;
    limit = (unsigned long long)LLONG_MAX;
    if (sign < 0)
        limit++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (false);
        digit = (*str++ - '0');
        if (number > (limit - digit) / 10)
            return (false);
        number = number * 10 + digit;
    }
    if (sign < 0 && number == limit)
        return (*exit_code = LLONG_MIN, true);
    *exit_code = (long long)number * sign;
    return (true);
}

static bool arg_to_exit_code(char *str, long long *exit_code)
{
    int     sign;
    size_t  i;

    i = 0;
    sign = 1;
    if (!str || !*str)
        return (false);
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i] || !convert_to_num(&str[i], sign, exit_code))
        return (false);
    return (true);
}

int	built_in_exit(char **argv, int n_arg)
{
	long long exit_code;

    if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
        exit_shell(_exit_status(EXTRACT, 0) & 0b11111111);
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
