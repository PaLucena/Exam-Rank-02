#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	do_op(char *n1, char *n2, char *oper)
{
	int	x = atoi(n1);
	int	y = atoi(n2);
	int	z;

	if (oper[0] == '+')
		z = x + y;
	else if (oper[0] == '-')
		z = x - y;
	else if (oper[0] == '*')
		z = x * y;
	else if (oper[0] == '/')
		z = x / y;
	else if (oper[0] == '%')
		z = x % y;
	printf("%i\n", z);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[3], av[2]);
	else
		write(1, "\n", 1);
	return (0);
}