#include <stdlib.h>
#include <stdio.h>

char	*ft_to_char(int nbr, char *nb_ch, int len)
{
	if (nbr > 9)
		ft_to_char(nbr / 10, nb_ch, len - 1);
	nb_ch[len - 1] = nbr % 10 + '0';
	return (nb_ch);
}

char	*ft_itoa(int nbr)
{
	char	*nb_ch;
	int		nbr2;
	int		len;
	int		pta;

	len = 0;
	pta = 0;
	if (nbr < 0)
	{
		len++;
		pta = -1;
		nbr *= -1;
	}
	nbr2 = nbr;
	while (nbr2 > 0)
	{
		nbr2 /= 10;
		len++;
	}
	nb_ch = malloc((len + 1) * sizeof(char));
	ft_to_char(nbr, nb_ch, len);
	if (pta < 0)
		nb_ch[0] = '-';
	nb_ch[len] = '\0';
	return (nb_ch);
}

int	main(void)
{
	char	*str;

	str = ft_itoa(12);
	printf("%s", str);
	return (0);
}