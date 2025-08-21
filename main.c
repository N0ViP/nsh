
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", argc - 1);
	while (*argv)
	{
		printf("[%s]\n", *argv++);
	}
}
