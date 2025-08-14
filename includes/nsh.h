/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:39 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/08 06:01:08 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NSH_H
# define NSH_H

# include "tokenization.h"
# include "parse_tree.h"
# include "allocation.h"
# include "execution.h"
# include "expansion.h"
# include "built-in.h"
# include "getenv.h"

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

#define SHELL		"nsh"
#define ARENA_SIZE	4096
#define WHITE_SPACE	" \t\n"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_list_info
{
	t_list		*list;
	t_list		*tail;
	size_t		size;
}	t_list_info;

typedef struct s_token
{
	char			*value;
	enum e_operator	type;
}	t_token;

bool	init(void);
void 	signals_setup(void);
void	new_shell(char *cmd);
bool	read_command(char **cmd);

//printers to remove
void    print_tokens(t_list *list);
void    tree_printer_00(t_tree *root, int indent);
void    tree_printer_01(t_tree *node, const char *prefix, bool is_left, bool is_first);
void 	print_all_sections();

#endif
