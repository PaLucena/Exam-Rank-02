#include <unistd.h>

int	to_number(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	while (str[++i])
		nb = nb * 10 + (str[i] - '0');
	return (nb);
}

void	write_res(int result)
{
	char	res_ch;

	if (result > 9)
		write_res(result / 10);
	res_ch = result % 10 + '0';
	write(1, &res_ch, 1);
}

void	tab_mult(char *str)
{
	int		i;
	int		nb;
	char	factor;
	int		result;

	nb = to_number(str);
	factor = '1';
	while (factor <= '9')
	{
		i = -1;
		write(1, &factor, 1);
		write(1, " x ", 3);
		while (str[++i] != '\0')
			write(1, &str[i], 1);
		write(1, " = ", 3);
		result = nb * (factor - '0');
		write_res(result);
		write(1, "\n", 1);
		factor++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}