#include "expansion.h"

void	utils(t_info *info, size_t i, size_t j)
{
	char	*word;
	char	*tmp;

	word = ft_substr(info->str, i, j);
	tmp = join_two_strings(info->word, word, "");
	info->word = tmp;
}
