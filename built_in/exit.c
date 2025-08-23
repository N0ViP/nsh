/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:20:30 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 23:35:03 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	process_exit(char **argv, int n_arg)
{
	long long	exit_code;

	if (n_arg > 1)
	{
		exit_code = 0;
		if (!arg_to_exit_code(argv[1], &exit_code))
		{
			print_exit_error(" numeric argument required\n", argv[1]);
			exit_shell(2);
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

int	built_in_exit(t_cmd *cmd_args)
{
	if (iam_a_child(EXTRACT))
		return (process_exit(cmd_args->args, cmd_args->n_arg));
	write(STDERR_FILENO, "exit\n", 5);
	return (process_exit(cmd_args->args, cmd_args->n_arg));
}
