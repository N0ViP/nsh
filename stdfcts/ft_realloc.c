#include "stdfcts.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	n;

	new_ptr = malloc(new_size);
	n = ft_min(old_size, new_size);
	ft_memcpy(new_ptr, ptr, n);
	return (new_ptr);
}