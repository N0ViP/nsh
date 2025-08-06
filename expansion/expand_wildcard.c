#include "expansion.h"

static void	get_wildcard_expand(t_list_info *arg, char **arr, char **hasmap)
{
	size_t	i;

	i = 0;
	
}

char	**expand_wildcard(t_info *info, t_list_info *arg_list)
{
	char		**splited_words;
	char		**splited_spaces;
	t_list_info	*arg;

	arg = init_list_info_struct();
	splited_words = ft_split(*word, " \t\n", false);
	splited_spaces = ft_split(*word, " \t\n", true);
	get_wildcard_expand(arg, splited_words, hashmap);
	*word = list_to_arr(arg);
}