#include <unistd.h>

void  recursive_hex(char *hex, int nb)
{
	if (nb >= 16)
		recursive_hex(hex, nb / 16);
	write(1, &hex[nb % 16], 1);
}

void    print_hex(char *str)
{
	char	hex[16] = "0123456789abcdef";
	int		nb = 0;
	int		i = -1;

	while (str[++i])
		nb = nb * 10 + (str[i] - '0');
	recursive_hex(hex, nb);
	}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	write(1, "\n", 1);
	return (0);
}