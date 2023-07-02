#include <unistd.h>

void	first_word(char *s)
{
	int	i = -1;

	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			if (s[i + 1] == ' ' || s[i] == '\t')
				break ;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		first_word(av[1]);
	write(1, "\n", 1);
	return (0);
}