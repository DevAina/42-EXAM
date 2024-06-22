/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:19:09 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/16 16:59:19 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	in_base(const char *str, int str_base)
{
	int	in_base;
	int	i;
	int	j;
	char *BASE;
	char *base;

	BASE = "0123456789ABCDEF";
	base = "0123456789abcdef";
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		j = 0;
		in_base = 0;
		while (j < str_base)
		{
			if (base[j] == str[i] || BASE[j] == str[i])
			{
				in_base = 1;
				break;
			}
			j++;
		}
		if (in_base == 0)
			return (0);
		i++;
	}
	return (1);
}

int	convert_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	if (in_base(str, str_base) == 0)
		return (0);
	if (str_base < 2 || str_base > 16)
		return (0);
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res = (res * str_base) + convert_to_value(str[i]);
		i++;
	}
	return (res * sign);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	return (0);
}
