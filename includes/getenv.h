#ifndef FT_GETENV_H
# define FT_GETENV_H

# define GET_ENV			1
# define ADD_IN_ENV			2
# define REMOVE_FROM_ENV	3

#include <stddef.h>
#include "stdfcts.h"
#include "nsh.h"

extern char	**environ;

typedef struct s_list		t_list;

t_list	*init_env();
char	*get_var_value(char *var);
t_list	*ft_getenv(int flag, char *var);
bool	ft_strcmp_env(char *s1, char *s2);
void	add_in_env(t_list **env, char *var);
void	remove_from_env(t_list **env, char *var);

#endif
