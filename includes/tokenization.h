/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 03:44:10 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/02 03:44:12 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

# include "nsh.h"
# include "utils.h"
# include "stdfcts.h"
# include <unistd.h>

typedef struct s_list		t_list;
typedef struct s_list_info	t_list_info;

t_list_info	*tokenize(char *cmd);
void		free_token(t_list *tokens);

#endif
