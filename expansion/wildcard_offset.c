#include "expansion.h"

size_t	wildcard_offset(int flag)
{
	static size_t	offset;

	if (flag == NEXT_OFFSET)
	{
		offset++;
	}
	else if (flag == PREV_OFFSET && offset)
	{
		offset--;
	}
	else if (flag == RESET_OFFSET)
	{
		offset = 0;
	}
	return (offset);
}
