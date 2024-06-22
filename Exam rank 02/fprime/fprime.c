#include <stdio.h>
#include <stdlib.h>

int	is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
	
}

int	main(int argc, char **argv)
{
	int	factor;
	int	first;
	int	n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		factor = 2;
		first = 1;
		while (factor <= n)
		{
			if (is_prime(factor) && n % factor == 0)
			{
				if (first == 1)
				{
					printf("%d", factor);
					first++;
				}
				else
					printf("*%d", factor);
				n = n / factor;
			}
			else
				factor++;
		}
	}
	printf("\n");
	return (0);
}
