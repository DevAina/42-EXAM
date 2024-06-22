#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	count_words(char *str)
{
	int	words;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	words = 0;
	while (i < len)
	{
		while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] >= 33 && str[i] <= 126)
		{
			while(str[i] >= 33 && str[i] <= 126)
				i++;
			words++;
		}
	}
	return (words);
}

int	ft_len_word(char *str, int index)
{
	int	len_word;
	int	i;
	int	len;

	i = index;
	len_word = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] >= 33 && str[i] <= 126)
		{
			while(str[i] >= 33 && str[i] <= 126)
			{
				len_word++;
				i++;
			}
			return (len_word);
		}
	}
	return (len_word);
}

char	**ft_split(char *str)
{
	int	words;
	int	len;
	int	len_words;
	int	i;
	int	j;
	int	count;
	char	**split;

	words = count_words(str);
	len = ft_strlen(str);
	i = 0;
	count = 0;
	split = malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	while (i < len && count < (words + 1))
	{
		while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		if (str[i] >= 33 && str[i] <= 126)
		{
			j = 0;
			len_words = ft_len_word(str, i);
			split[count] = malloc(sizeof(char) * (len_words + 1));
			while (j < len_words)
			{
				split[count][j] = str[i];
				j++;
				i++;
			}
			split[count][j] = '\0';
			count++;
		}
	}
	split[count] = NULL;
	return (split);
}