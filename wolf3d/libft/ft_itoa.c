/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:49:48 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 11:10:18 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_intlen(int n)
{
	unsigned int	abs;
	int				dest;

	dest = (n < 0 ? 1 : 0);
	abs = ABS(n);
	while (abs > 0)
	{
		abs /= 10;
		dest++;
	}
	return (dest);
}

char			*ft_itoa(int n)
{
	size_t			i;
	unsigned int	abs;
	char			*dst;
	char			neg;

	i = (n == 0 ? 1 : ft_intlen(n));
	dst = (char *)malloc(sizeof(char) * i + 1);
	if (dst == NULL)
		return (NULL);
	neg = (n >= 0 ? 0 : 1);
	abs = ABS(n);
	dst[0] = '0';
	dst[i] = '\0';
	while (abs != 0)
	{
		i--;
		dst[i] = abs % 10 + '0';
		abs /= 10;
		if (abs == 0)
			break ;
	}
	if (neg)
		dst[0] = '-';
	return (dst);
}
