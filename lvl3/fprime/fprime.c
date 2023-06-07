#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	int	nb;
	int	i;

	i = 2;
	nb = atoi(str);
	if (nb == 1)
		printf("1");
	while (nb >= i)
	{
		while (nb % i == 0)
		{
			nb /= i;
			printf("%i", i);
			if (nb == i || nb == 1)
				break ;
			printf("*");
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}