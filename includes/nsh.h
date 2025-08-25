/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:39 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/23 22:24:02 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NSH_H
# define NSH_H

# include "librairies.h"

# include "tokenization.h"
# include "parse_tree.h"
# include "execution.h"
# include "expansion.h"
# include "mem_track.h"
# include "built_in.h"
# include "heredoc.h"
# include "stdfcts.h"
# include "getenv.h"
# include "utils.h"

extern int			g_signaled;

# define SHELL "nsh"
# define INITIAL_CAPACITY 64
# define WHITE_SPACE " \t\n"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list_info
{
	t_list			*list;
	t_list			*tail;
	size_t			size;
}					t_list_info;

typedef struct s_token
{
	char			*value;
	enum e_type		type;
}					t_token;

bool				init(void);
void				new_shell(char *cmd);
void				read_mode_signals(void);
bool				read_command(char **cmd);
void				child_mode_signals(void);
void				parent_mode_signals(void);
void				exit_shell(int exit_status);

#endif
