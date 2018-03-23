/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 10:29:06 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/23 11:11:35 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*recursiv(long int number, char *str, int base, int len)
{
	if (number > 0)
	{
		recursiv(number / base, str, base, len - 1);
	}
	str[len] = number % base + 48;
	return (str);
}

static char		*attribute_letter(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' && str[i] < '9' + 7)
			str[i] = str[i] - ':' + 'A';
		i++;
	}
	return (str);
}

static long int	modif_len(long int cpy, long int len, int base)
{
	while (cpy > 0)
	{
		cpy = cpy / base;
		len++;
	}
	return (len);
}

static long int	*get_len_sign_and_i(int value, int base)
{
	long int	cpy;
	long int	*glob;

	if ((glob = (long int*)malloc(sizeof(long int) * 3)) == NULL)
		return (NULL);
	glob[1] = 0;
	glob[0] = 0;
	glob[2] = value;
	cpy = value;
	if (cpy < 0)
	{
		if (base == 10)
		{
			glob[1] = 1;
			glob[0]++;
		}
		cpy = -cpy;
		glob[2] = -glob[2];
	}
	else if (cpy == 0)
		glob[0] = 1;
	glob[0] = modif_len(cpy, glob[0], base);
	return (glob);
}

char			*ft_itoa_base(int value, int base)
{
	long int	i;
	long int	len;
	int			sign;
	char		*str;
	long int	*glob;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	if ((glob = get_len_sign_and_i(value, base)) == NULL)
		return (NULL);
	len = glob[0];
	sign = glob[1];
	i = glob[2];
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (0);
	str[len] = '\0';
	str = recursiv(i, str, base, len - 1);
	if (sign)
		str[0] = '-';
	str = attribute_letter(str);
	return (str);
}
