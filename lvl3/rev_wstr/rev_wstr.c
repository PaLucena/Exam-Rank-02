#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int	word_count(char *str)
{
	int		i = 0;
	int		w = 0;
	bool	p = 1;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && p)
		{
			w++;
			p = false;
		}
		else if (str[i] == ' ' || str[i] == '\t')
			p = true;
		i++;
	}
	return (w);
}

char	*fill_word(int start, int len, char *str)
{
	char	*word;
	int		i = 0;

	word = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_putstr(char *str)
{
	int	i = -1;

	while (str[++i])
		write(1, &str[i], 1);
}

void	rev_wstr(char *str)
{
	char	**array;
	int		i = 0;
	int		j;
	int		k = 0;

	k = word_count(str);
	array = malloc(sizeof(char *) * (k + 1));
	if (!array)
	{
		free(array);
		exit (1);
	}
	k = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			while (str[i + j] != ' ' && str[i + j] != '\t' && str[i + j])
				j++;
			array[k] = fill_word(i, j, str);
			k++;
			i += j;
		}
		else
			i++;
	}
	array[k] = NULL;
	while (array[--k])
	{
		ft_putstr(array[k]);
		if (array[k - 1] != NULL)
			write(1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}