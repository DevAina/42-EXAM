#include <unistd.h>
#include <stdio.h>

int custom_is_print(char c)
{
	return (c >= 33 && c <= 126);
}

void	expand_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
		{
			if (custom_is_print(str[i]) && str[i - 1] == ' ')
			{
				j = 0;
				while (j < 3)
				{
					write(1, " ", 1);
					j++;
				}
				write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		expand_str(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
