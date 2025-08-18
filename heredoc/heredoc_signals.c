# include "heredoc.h"

int heredoc_exit = 0;// g_

static int nothing(void)
{
    return 0;
}

static void heredoc_sigint(int signal)
{
    (void)signal;
    _exit_status(UPDATE, 130);
    heredoc_exit = 130;
    rl_done = 1;
}

void heredoc_signals(void)
{
    rl_event_hook = nothing;
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, heredoc_sigint);
}
