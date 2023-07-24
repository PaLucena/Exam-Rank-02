#include <unistd.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	i = 0;
	int	p = 0;
	int	c = 0;

	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
		{
			if (p == 0)
			{
				p = 1;
				c++;
			}
		}
		else if (p == 1)
			p = 0;
		i++;
	}
	return (c);
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*fill_words(char *src, char *dst, int start, int total)
{
	int	i = 0;

	while ((start + i) < total && src[start + i])
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	rev_wstr(char *str)
{
	char	**array;
	int		i;
	int		j = 0;
	int		k = 0;

	array = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!array)
		exit(1);
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' '))
			i--;
		while (str[i - j] != '\t' && str[i - j] != ' ')
			j++;
		array[k] = malloc(sizeof(char) * (j + 1));
		if (!array[k])
			exit(1);
		array[k] = fill_words(str, array[k], j, i);
		i -= j;
		k++;
	}
	array[k] = NULL;
	k = -1;
	while (array[++k] != NULL)
		write(1, &array[k], ft_strlen(array[k]));
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1,"\n", 1);
	return (0);
}
