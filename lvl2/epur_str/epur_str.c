#include <unistd.h>

void	epur_str(char *str)
{
	int	i = 0;
	int	p = 1;

	while (str[i])
	{
		if (str[i] && str[i] != '\t' && str[i] != ' ')
		{
			write(1, &str[i], 1);
			p = 0;
		}
		else if (p == 0 && str[i + 1] != '\0' && str[i + 1] != '\t' && str[i + 1] != ' ')
		{
			write(1, " ", 1);
			p = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
