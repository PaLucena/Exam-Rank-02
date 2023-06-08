#include <unistd.h>

void	search_and_replace(char *str, char *a, char *b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a[0])
			str[i] = b[0];
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
		search_and_replace(av[1], av[2], av[3]);
	write(1, "\n", 1);
	return (0);
}