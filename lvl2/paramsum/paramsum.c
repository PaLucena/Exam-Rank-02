#include <unistd.h>
#include <stddef.h>

void	print_nb(int nb)
{
	char	a;

	if (nb > 9)
		print_nb(nb / 10);
	a = nb % 10 + '0',
	write(1, &a, 1);
}

void	paramsum(char **av)
{
	char	n;
	int		i = 1;

	while (av[i] != NULL)
		i++;
	i--;
	if (i > 9)
		print_nb(i);
	else
	{
		n = i + '0';
		write(1, &n, 1);
	}
}

int	main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
		paramsum(av);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}