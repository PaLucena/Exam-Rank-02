/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:16:24 by palucena          #+#    #+#             */
/*   Updated: 2023/06/02 18:35:34 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i])
	{
		c = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - ('a' - 1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = str[i] - ('A' - 1);
		else
			write(1, &str[i], 1);
		while (c > 0)
		{
			write(1, &str[i], 1);
			c--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
