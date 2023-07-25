#include <unistd.h>

void	str_capitalizer(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' ' || str[i - 1] == '\t' || i == 0))
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && str[i - 1] != ' ' && str[i] != '\t' && i != 0)
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
			str_capitalizer(av[i]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
