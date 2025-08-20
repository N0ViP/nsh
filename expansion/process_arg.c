#include "expansion.h"

static bool	check_wildcard(bool *hashmap, char *word)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '*' && hashmap[wildcard_offset(CURR_OFFSET)])
		{
			wildcard_offset(RESET_OFFSET);
			return (true);
		}
		else if (word[i] == '*' && !hashmap[wildcard_offset(CURR_OFFSET)])
		{
			wildcard_offset(NEXT_OFFSET);
		}
		i++;
	}
	wildcard_offset(RESET_OFFSET);
	return (false);
}

static void	add_in_args_list(t_list_info *args, char *dname)
{
	t_list	*node;

	node = creat_node(dname);
	list_add_back(args, node);
}

static bool	match_here(const char *p, const char *w, bool *hashmap)
{
	if (*p == '\0')
		return (*w == '\0');
	if (*p == '*' && wildcard_offset(CURR_OFFSET))
	{
		wildcard_offset(NEXT_OFFSET);
		return (match_here(p + 1, w, hashmap)
			|| (*w && match_here(p, w + 1, hashmap)));
	}
	wildcard_offset(NEXT_OFFSET);
	return (*p == *w && match_here(p + 1, w + 1, hashmap));
}

static bool	if_match(bool *hashmap, char *pattern, char *word)
{
	return (match_here(pattern, word, hashmap));
}

static t_list_info	*expand_wildcard(bool *hashmap, char *word)
{
	t_list_info		*args;
	DIR				*dirp;
	struct dirent	*dirent;
	char			*dname;

	args = init_list_info_struct();
	dirp = opendir(".");
	dirent = readdir(dirp);
	while (dirent)
	{
		if ((dirent->d_name[0] != '.' || word[0] == '.')
			&& if_match(hashmap, word, dirent->d_name))
		{
			dname = ft_strdup(dirent->d_name);
			add_in_args_list(args, dname);
		}
		dirent = readdir(dirp);
	}
	closedir(dirp);
	if (!args->size)
	{
		add_in_args_list(args, word);
	}
	return (args);
}

void	process_arg(t_info *info, t_list_info *arg_list)
{
	char		*word;
	t_list		*node;
	t_list_info	*expanded_wildcard;

	if (!info->ex_word->list)
	{
		return ;
	}
	word = join_list_content(info->ex_word->list, "", info->len);
	if (check_wildcard(info->hashmap, word))
	{
		expanded_wildcard = expand_wildcard(info->hashmap, word);
		join_list(arg_list, expanded_wildcard);
	}
	else
	{
		node = creat_node(word);
		list_add_back(arg_list, node);
	}
	add_in_wildcard_hashmap(0, RESET_OFFSET, false);
	wildcard_offset(RESET_OFFSET);
}
