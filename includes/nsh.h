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
	char			*token;
	struct s_tokens	*next;
} t_tokens;
