#include <unistd.h>

void	fizzbuzz(void)
{
	int		i = 0;
	char	a;
	char	b;

	while (++i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			if (i > 9)
			{
				b = (i / 10) + '0';
				write(1, &b, 1);
			}
			a = (i % 10) + '0';
			write(1, &a, 1);
		}
		write(1, "\n", 1);
	}
}

int	main(void)
{
	fizzbuzz();
	return (0);
}