# include "heredoc.h"

char	*num_to_str(unsigned long v)
{
	unsigned long	tmp;
	int				digits;
	char			*s;

	tmp = v;
	digits = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		digits++;
	}
	s = new_allocation(EXECUTION, digits + 1);
	s[digits] = '\0';
	while (digits > 0)
	{
		digits--;
		s[digits] = '0' + (v % 10);
		v /= 10;
	}
	return (s);
}
