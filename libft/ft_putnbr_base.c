/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 17:18:21 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/23 11:10:05 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_error(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

static void		limite(long int n, char *base, int u)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= u)
		limite(n / u, base, u);
	ft_putchar(base[(n % u)]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int			u;
	long int	n;

	u = ft_strlen_error(base);
	if (nbr == -2147483648 && u > 1)
	{
		n = -2147483648;
		limite(n, base, u);
	}
	else if (u > 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		if (nbr >= u)
			ft_putnbr_base(nbr / u, base);
		ft_putchar(base[(nbr % u)]);
	}
}
