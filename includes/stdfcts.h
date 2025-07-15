/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfcts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:51 by yjaafar           #+#    #+#             */
/*   Updated: 2025/07/07 23:57:02 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDFCTS_H
# define STDFCTS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

bool	ft_isspace(int c);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s, size_t n);
char	**ft_split(const char *s, char c);

#endif