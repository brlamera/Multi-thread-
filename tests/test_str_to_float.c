/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_to_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:03:19 by juthomas          #+#    #+#             */
/*   Updated: 2017/12/04 22:21:42 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int		ft_atof_start(char *str)
{
	int		i;
	int		pos;
	int		tmp;
	int		done;

	done = 0;
	i = 0;
	pos = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		pos = ((str[i] >= '1' && str[i] <= '9') && pos == 0 ) ? i + 1 : pos;
		i++;
		if (pos != 0)
			done = 1;
	}
	if (pos != 0)
		pos = i + 1 - pos;
	else
		pos = -1;
	tmp = i;
/*	if (str[i] == '.' && done == 0)
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			pos = ((str[i] >= '1' && str[i] <= '9') && pos == 0 ) ? i : pos;
			i++;
		}
		if (pos != 0)
			pos = tmp - pos;
	}*/
	return (pos);
}

int		ft_atof_power(int nb, int power)
{
	int	ret;

	ret = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		ret *= nb;
		power--;
	}
	return (ret);
}

float	ft_atof_how_power(int i)
{
	if (i > 0)
		return ((float)ft_atof_power(10, i - 1));
	else if (i < 0)
		return (0.1);
		//return ((float)(1.0 / (float)ft_atof_power(10, -i)));
	return (0);
}

double	ft_atof(char *str)
{
	double	ret;
	int		i;
	int		sg;
	int		tmp;
	float	rap;

	ret = 0;
	i= 0;
	while ((str[i] == ' ') || (str[i] == '	') || (str[i] == '\n') 
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
	tmp = i;
	while (str[tmp] >= '0' && str[tmp] <= '9')
		tmp++;
	tmp = tmp - i;
	printf("ret = %f\n", ft_atof_how_power(ft_atof_start(&str[i])));
	rap = ft_atof_how_power(ft_atof_start(&str[i]));
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret + ((str[i] - '0') * rap);
		rap = rap / 10;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			ret = ret + ((float)(str[i] - '0') * rap);
		//	printf("test=%f	;	", ((float)(str[i] - '0') * rap));
			rap = rap / 10;
			i++;
		}
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	float		i;

	i = 0;
	if (argc == 2)
	{
		printf("return mine= %f\n",ft_atof(argv[1]));
		printf("return your= %f", atof(argv[1]));
	}


}
