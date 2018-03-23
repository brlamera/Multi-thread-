/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:02:36 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/23 11:10:55 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen_error(char *base)
{
	int		i;
	int		j;

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

static int		stri_is_good(char h, char *base)
{
	int		u;
	int		y;

	u = 0;
	y = 0;
	while (base[u] != '\0')
	{
		if (base[u] == h)
			y++;
		u++;
	}
	if (y == 1)
		return (0);
	else
		return (1);
}

static int		nb_de_la_base(char h, char *base)
{
	int		x;

	x = 0;
	while (base[x] != h)
		x++;
	return (x);
}

static int		test_str(char *str, char *base)
{
	int		m;
	int		n;
	int		ok;

	ok = 0;
	m = 0;
	n = 0;
	while (str[m] != '\0')
	{
		ok = 0;
		while (base[n] != '\0' && ok == 0)
		{
			if (str[m] == base[n])
				ok++;
			if (m == 0 && (str[0] == '+' || str[0] == '-'))
				ok++;
			n++;
		}
		if (ok == 0)
			return (1);
		m++;
		n = 0;
	}
	return (0);
}

int				ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		i;
	int		sg;

	nb = 0;
	i = 0;
	sg = 1;
	if (ft_strlen_error(base) <= 1)// || test_str(str, base) == 1)
		return (0);
	while ((str[i] == ' ') || (str[i] == '	'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sg *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (stri_is_good(str[i], base))
			return (nb * sg);
		nb = nb * ft_strlen_error(base) + (nb_de_la_base(str[i], base));
		i++;
	}
	return (nb * sg);
}
