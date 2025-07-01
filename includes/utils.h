#ifndef UTILS_H
# define UTILS_H

# include "nsh.h"

void		free_tokens(t_tokens *tokens);
t_tokens	*creat_token_node(char *token);
char		*ft_substr(char *cmd, int i, int j);

#endif