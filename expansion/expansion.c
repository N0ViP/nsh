/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:42:03 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/26 08:48:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "nsh.h"

size_t	get_normal_word(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\''
		&& str[i] != '"' && str[i] != '$')
	{
		i++;
	}
	return (i);
}

int	expander(char *str, t_list_info *expand)
{
	size_t		i;
	size_t		n;
	t_list_info	value;

	i = 0;
	while (str[i])
	{
		n = get_normal_word(str + i);
		
		
	}
}

char **expansion(t_list *lst)
{
	t_list_info	*expand;
	char		**res;
	
	expand = init_list_info_struct();
	if (!expand)
		return (NULL);
	while (lst)
	{
		if (expander(((t_token *)lst->content)->value, expand))
			return (free(expand), NULL);
		lst = lst->next;
	}
	res = create_array(expand);
	return (res);
}
