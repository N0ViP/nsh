# include "nsh.h"

int g_signaled = 0;

static int nothing(void)
{
    return 0;
}

static void heredoc_sigint(int signal)
{
    (void)signal;
    _exit_status(UPDATE, 130);
    g_signaled = SIGINT;
    rl_done = 1;
}

void heredoc_mode_signals(void)
{
    rl_event_hook = nothing;
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, heredoc_sigint);
}
