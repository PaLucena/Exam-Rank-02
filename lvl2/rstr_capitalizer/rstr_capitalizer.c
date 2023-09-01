#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

void	rstr_capitalizer(char *str)
{
	int		i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 1)
		write(1, "\n", 1);
	while (av[++i] != NULL)
	{
		rstr_capitalizer(av[i]);
		write(1, "\n", 1);
	}
	return (0);
}
