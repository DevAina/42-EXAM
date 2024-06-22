/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:22:51 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/16 11:31:50 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

int	in_str2(char *str2, char c)
{
	int i;

	i = 0;
	while (str2[i] != '\0')
	{
		if (str2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter_print(char *str1, char *str2)
{
	bool ascii[256] = { false };

	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (in_str2(str2, str1[i]) && ascii[(unsigned int)str1[i]] == false)
		{
			ascii[(unsigned int)str1[i]] = true;
			write(1, &str1[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter_print(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
