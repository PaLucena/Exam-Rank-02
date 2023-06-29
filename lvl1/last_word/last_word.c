#include <unistd.h>

void	last_word(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i])
	{
		i--;
		if (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && (s[i - 1] == ' ' || s[i - 1] == '	'))
			break ;
	}
	while (s[i] && s[i] != ' ' && s[i] != '	')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}