#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int	c = 0;
	int	i = 0;
	int	p = 1;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if (p == 1)
			{
				c++;
				p = 0;
			}
			else
				i++;
		}
		else
		{
			p = 1;
			i++;
		}
	}
	return (c);
}

void	fill_word(char *src, char *dst, int start, int total)
{
	int	i = 0;

	while (src[i] != '\0' && i < total)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		j;
	int		k = 0;
	int		count;
	char	**array;

	count = count_words(str);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (0);
	while (k < count && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = 0;
		while (str[i + j]  != ' ' && str[i + j]  != '\t' && str[i + j]  != '\n')
			j++;
		array[k] = malloc(sizeof(char) * (j + 1));
		if (!array[k])
			return (0);
		fill_word(str, array[k], i, j);
		i += j;
		k++;
	}
	array[k] = NULL;
	return(array);
}

int	main(void)
{
	int	i = -1;
	char	**array;

	array = ft_split("pa1 tgt gtgtgtgt   ");
	while (array[++i] != 0)
		printf("%s\n", array[i]);
	return (0);
}