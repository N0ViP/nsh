#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>


typedef struct s_tokens
{
	char			*word;
	struct s_tokens	*next;
} t_tokens;


void		free_tokens(t_tokens *tokens);
t_tokens	*creat_token_node(char *token);
char		*ft_substr(char *cmd, int i, int j);
void		add_node_back(t_tokens **list, t_tokens *node);

bool	ft_isspace(int c);
