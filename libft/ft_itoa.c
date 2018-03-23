/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 01:40:40 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/23 11:45:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*recursiv_powa(char *str, int len, long int nbr)
{
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr / 10 != 0)
		recursiv_powa(str, len - 1, nbr / 10);
	str[len] = nbr % 10 + 48;
	return (str);
}

static int		len_part(long int cpy2, int len)
{
	if (cpy2 == 0)
		return (1);
	while (cpy2 / 10 != 0)
	{
		cpy2 = cpy2 / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	long int	cpy1;
	long int	cpy2;
	short int	sign;
	char		*str;
	int			len;

	cpy1 = nbr;
	cpy2 = nbr;
	len = 0;
	sign = 0;
	len = len_part(cpy2, len);
	if (cpy1 < 0)
	{
		cpy2 = -cpy2;
		cpy1 = -cpy1;
		len++;
		sign = 1;
	}
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str = recursiv_powa(str, len, cpy1);
	str[len + 1] = '\0';
	if (sign)
		str[0] = '-';
	return (str);
}
