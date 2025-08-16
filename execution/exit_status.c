#include "execution.h"

int	_exit_status(bool flag, int value)
{
	static int	exit_status;

	if (flag == UPDATE)
	{
		exit_status = value;
	}
	return (exit_status);
}
