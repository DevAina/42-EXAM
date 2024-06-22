/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 10:52:32 by trarijam          #+#    #+#             */
/*   Updated: 2024/06/16 11:16:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	print_string(char *str, bool *ascii)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ascii[(unsigned char)str[i]])
		{
			ascii[(unsigned char)str[i]] = true;
			write(1, &str[i], 1);
		}
		i++;
	}
}


/*Pour gérer les doublons, il faut utiliser un tableau de *
 *booléens avec une taille de 256 initialisé à false pour *
 *suivre les caractères déjà affichés. 256 pour couvrir les *
* caracteres possibles de l'ASCII*/

int	main(int argc, char **argv)
{
	bool ascii[256] = { false };

	if (argc == 3)
	{
		print_string(argv[1], ascii);
		print_string(argv[2], ascii);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
