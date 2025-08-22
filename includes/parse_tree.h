/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:26:50 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 06:54:23 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TREE_H
# define PARSE_TREE_H

# include "nsh.h"

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;
typedef struct s_token		t_token;

typedef enum e_type
{
	WORD,
	OP_OR,
	OP_AND,
	OP_PIPE,
	OP_APPEND,
	OP_HEREDOC,
	OP_REDIR_OUT,
	OP_REDIR_IN,
	OP_OPEN_PARENTHESE,
	OP_CLOSED_PARENTHESE,
	SUBSHELL,
	COMMAND
}							t_type;

typedef struct s_redir
{
	t_type					type;
	void					*file;
}							t_redir;

typedef struct s_cmd
{
	char					**args;
	int						n_arg;
	t_redir					*redirs;
	int						n_redirs;
}							t_cmd;

typedef struct s_branch
{
	struct s_tree			*left;
	struct s_tree			*right;
}							t_branch;

typedef struct s_subshell
{
	struct s_tree			*child;
	t_redir					*redirs;
	int						n_redirs;
}							t_subshell;

typedef struct s_tree
{
	t_type					type;
	union
	{
		t_cmd				cmd;
		t_branch			branch;
		t_subshell			subshell;
	} u_data;
}							t_tree;

bool						parse_check(t_list *tokens);
int							count_redirs(t_list *tokens);
t_tree						*parse_tokens(t_list *tokens);
t_tree						*parse_in_tree(t_list *tokens);
void						parse_error(const char *token);
t_tree						*new_command_branch(t_list *tokens);
t_tree						*new_subshell_branch(t_list *tokens);
t_redir						*extract_redirs(t_list **tokens, int n_redirs);
t_tree						*new_operator_branch(t_list *tokens, t_list *split);

#endif