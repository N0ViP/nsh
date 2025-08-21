#include "nsh.h"

static void shell_sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();//
    rl_redisplay();
}

void read_mode_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, shell_sigint);
}

void child_mode_signals(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}

void parent_mode_signals(void)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}
