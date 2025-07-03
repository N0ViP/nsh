/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:39 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/01 08:40:41 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NSH_H
# define NSH_H

# include "tokenization.h"

# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_list_info
{
	t_list		*list;
	t_list		*tail;
	int			size;
}	t_list_info;

enum e_operator {
	WORD,
	OP_OR,
	OP_AND,
	OP_APPEND,
	OP_HEREDOC,
	OP_REDIR_OUT,
	OP_REDIR_IN,
	OP_PIPE	
};

typedef struct s_token
{
	char			*value;
	enum e_operator	type;
}	t_token;

#endif
