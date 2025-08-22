/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfcts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:40:51 by yjaafar           #+#    #+#             */
/*   Updated: 2025/08/10 18:03:33 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDFCTS_H
# define STDFCTS_H

# include "nsh.h"

int		ft_abs(int x);
char	*ft_itoa(int n);
size_t	ft_numlen(int n);
bool	ft_isdigit(int a);
bool	ft_isalpha(int a);
bool	ft_isalnum(int a);
bool	ft_isspace(int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
size_t	ft_min(size_t a, size_t b);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char *sep);
char	*ft_strcat(char *dest, char *src);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *str, char c);
char	*ft_substr(char *str, int i, int j);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char **arr, char *delemiter);
void	*ft_memcpy(void *d, void *s, size_t len);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif