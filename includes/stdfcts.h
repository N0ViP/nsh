/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfcts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:51 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/06 02:04:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDFCTS_H
# define STDFCTS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

bool	ft_isdigit(int a);
bool	ft_isalpha(int a);
bool	ft_isalnum(int a);
bool	ft_isspace(int c);
size_t  ft_strlen(const char *s);
char	*ft_strchr(const char *str, char c);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
int 	ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(const char *str, int i, int j);
char	*ft_strjoin(char **arr, const char *delemiter);
void	*ft_memcpy(void *d, const void *s, size_t len);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	**ft_split(const char *s, const char *sep);

#endif