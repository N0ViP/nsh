/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoummad <ahoummad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 05:34:17 by ahoummad          #+#    #+#             */
/*   Updated: 2025/08/22 05:34:18 by ahoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdfcts.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	n;

	new_ptr = allocate_memory(new_size);
	n = ft_min(old_size, new_size);
	ft_memcpy(new_ptr, ptr, n);
	free_one_pointer(*current_section(), ptr);
	return (new_ptr);
}
