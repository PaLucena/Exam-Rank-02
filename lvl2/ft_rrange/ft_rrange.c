#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*rg;

	i = 0;
	i = end - start + 1;
	rg = malloc((i + 1) * sizeof(int));
	i = 0;
	while (end >= start)
	{
		rg[i] = end;
		end--;
		i++;
	}
	rg[i] = '\0';
	return (rg);
}

/* #include <stdio.h>

int	main(void)
{
	int	i = 0;
	int	*rg);

	rg = ft_rrange(1, 2);
	while (rg[i])
	{
		printf("%i", rg[i]);
		i++;
	}
	return (0);
} */