#include <unistd.h>
#include <stdlib.h>

// write, exit

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	prime_check(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_result(int x)
{
	char	c;
 
	if (x > 9)
		print_result(x / 10);
	c = (x % 10) + '0';
	write(1, &c, 1);
}

void add_prime_sum(char *nb)
{
	int	x = ft_atoi(nb);
	int	c = 0;

	while (x > 1)
	{
		if (prime_check(x) == 1)
			c += x;
		x--;
	}
	print_result(c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		add_prime_sum(av[1]);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}