#include <unistd.h>

int	check_s1(char *s, int c)
{
	int	i = 0;
	while (i > c)
	{
		if (s[i] == s[c])
			return (0);
		i++;
	}
	return (1);
}

int	check_s2(char c, char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i])
	{
		if (check_s1(s1, i) > 0 && check_s2(s1[i], s2) > 0)
			write(1, &s1[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}