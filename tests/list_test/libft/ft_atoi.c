/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 15:47:24 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 10:51:11 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		nb;
	int		i;
	int		sg;

	nb = 0;
	i = 0;
	sg = 1;
	while ((str[i] == ' ') || (str[i] == '	') || (str[i] == '\n')
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			return ((int)(nb * sg));
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return ((int)(nb * sg));
}
