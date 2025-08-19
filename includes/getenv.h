#ifndef FT_GETENV_H
# define FT_GETENV_H

#include "nsh.h"

# define ADD_IN_ENV			1
# define REMOVE_FROM_ENV	2
# define EXPORT             true
# define UNSET              false

extern char	**environ;

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;

void        env_setup(void);
t_list_info	*init_env(void);
t_list_info	**env_list(void);
char		*get_var_value(char *var);
t_list_info	*ft_getenv(int flag, char *var);
int     	ft_strcmp_env(char *s1, char *s2);
void        set_var_value(char *key, char *value);
void		add_in_env(t_list_info *env, char *var);
void		remove_from_env(t_list_info *env, char *var);

#endif
