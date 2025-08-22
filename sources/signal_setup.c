/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:33:30 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 07:04:16 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nsh.h"

static void	shell_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	read_mode_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, shell_sigint);
}

void	child_mode_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	parent_handler(int signal)
{
	g_signaled = signal;
	if (signal == SIGINT)
	{
		(void)write(STDOUT_FILENO, "\n", 1);
	}
	else if (signal == SIGQUIT)
	{
		(void)write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	}
}

void	parent_mode_signals(void)
{
	signal(SIGINT, parent_handler);
	signal(SIGQUIT, parent_handler);
}
