#include "stdfcts.h"

void	*ft_memcpy(void *d, void *s, size_t len)
{
	void	*dest;

	if (!d || !s)
		return (NULL);
	dest = d;
	while (!((size_t) d % sizeof(size_t)) && len)
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}
	while (len >= sizeof(size_t))
	{
		*((size_t *) d) = *((size_t *) s);
		d += sizeof(size_t);
		s += sizeof(size_t);
		len -= sizeof(size_t);
	}
	while (len)
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}
	return (dest);
}
