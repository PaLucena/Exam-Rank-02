#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	camel_to_snake(char *camel)
{
	int		i;
	int		j;
	char	*snake;	

	i = 0;
	while (*camel)
	{
		if (*camel >= 'A' && *camel <= 'Z')
			i++;
		i++;
		camel++;
	}
	snake = malloc((i + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (camel[i] != '\0')
	{
		if (camel[i] >= 'A' && camel[i] <= 'Z')
		{
			snake[j] = '_';
			snake[++j] = camel[i] - 32;
		}
		else
			snake[j] = camel[i];
		i++;
		j++;
	}
	snake[j] = '\0';
	j = -1;
	while (snake[++j])
		write(1, &snake[j], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}