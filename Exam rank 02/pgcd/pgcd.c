#include <stdio.h>
#include <stdlib.h>

int	pgcd(unsigned int a, unsigned int b)
{
	if (b == 0)
		return (a);
	return (pgcd(b, a % b));
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
	}
	else
		printf("\n");
	return (0);
}
