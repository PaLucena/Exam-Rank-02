#include <unistd.h>
#include <stdbool.h>

void	expand_str(char *str)
{
	int	i = 0;
	bool	p = false;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			write(1, &str[i], 1);
			p = true;
		}
		else if (p && str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			write(1, "   ", 3);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}