#include "nsh.h"

static void sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void signals_setup(void)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, SIG_IGN);
}