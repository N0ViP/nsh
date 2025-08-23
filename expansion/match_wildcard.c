/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:42:34 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/23 02:59:58 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static void	reset_wildcard(size_t star_index)
{
	size_t	i;

	i = 0;
	wildcard_offset(RESET_OFFSET);
	while (i <= star_index)
	{
		wildcard_offset(NEXT_OFFSET);
		i++;
	}
}

static bool	handle_star(char **pattern, char *word, t_wild *wild)
{
	wild->star = *pattern;
	(*pattern)++;
	wild->star_index = wildcard_offset(CURR_OFFSET);
	wildcard_offset(NEXT_OFFSET);
	(void)word;
	return (true);
}

static bool	process_word(char **pattern, char **word, bool *hashmap,
		t_wild *wild)
{
	if (**pattern == **word)
	{
		if (*(*pattern)++ == '*')
			wildcard_offset(NEXT_OFFSET);
		(*word)++;
		return (true);
	}
	if (**pattern == '*' && hashmap[wildcard_offset(CURR_OFFSET)])
	{
		handle_star(pattern, *word, wild);
		wild->backup = *word;
		return (true);
	}
	if (wild->star)
	{
		*pattern = wild->star + 1;
		reset_wildcard(wild->star_index);
		*word = ++(wild->backup);
		return (true);
	}
	return (false);
}

static bool	check_remaining(char *pattern, bool *hashmap)
{
	while (*pattern)
	{
		if (*pattern != '*' || !hashmap[wildcard_offset(CURR_OFFSET)])
			return (false);
		wildcard_offset(NEXT_OFFSET);
		pattern++;
	}
	return (true);
}

bool	wildcard_match(char *pattern, char *word, bool *hashmap)
{
	t_wild	wild;

	wild.star = NULL;
	wild.backup = NULL;
	wild.star_index = 0;
	while (*word)
	{
		if (!process_word(&pattern, &word, hashmap, &wild))
			return (false);
	}
	return (check_remaining(pattern, hashmap));
}
