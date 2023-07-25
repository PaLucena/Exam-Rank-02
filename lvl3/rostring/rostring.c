#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

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

void    put_str(char **array)
{
    int    i = 0;
    int    j = -1;

    while (array[++i] != NULL)
    {
        while (array[i][++j])
        	write(1, &array[i][j], 1);
        write(1, " ", 1);
		j = -1;
	}
	while (array[0][++j])
		write(1, &array[0][j], 1);
}

void	rostring(char *str)
{
	int		i = 0;
	int		j;
	int		k = 0;
	int		count;
	char	**array;

	count = count_words(str);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		exit (1);
	while (k < count && str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = 0;
		while (str[i + j]  != ' ' && str[i + j]  != '\t' && str[i + j]  != '\n' && str[i + j] != '\0')
			j++;
		array[k] = malloc(sizeof(char) * (j + 1));
		if (!array[k])
			exit (1);
		fill_word(str, array[k], i, j);
		i += j;
		k++;
	}
	array[k] = NULL;
	put_str(array);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
