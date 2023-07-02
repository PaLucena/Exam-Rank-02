#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = -1;

	while (str[++i])
		write(1, &str[i], 1);
}

char	*asign_camel(char	*str)
{
	int		i = 0;
	int		space = 0;
	char	*camel;

	while (str[i])
	{
		i++;
		if (str[i] == '_')
			space++;
	}
	camel = malloc(sizeof(char) * (i - space + 1));
	return (camel);
}

void	snake_to_camel(char *sn)
{
	int		i = 0;
	int		j = 0;
	int		p = 0;
	char	*ca;

	ca = asign_camel(sn);
	while (sn[i])
	{
		if (sn[i] >= 'a' && sn[i] <= 'z' && p == 1)
		{
			ca[j] = sn[i] - 32;
			p = 0;
			i++;
			j++;
		}
		else if (sn[i] == '_')
		{
			i++;
			p = 1;
		}
		else
		{
			ca[j] = sn[i];
			i++;
			j++;
		}
	}
	ft_putstr(ca);
	free(ca);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1, "\n", 1);
	return (0);
}