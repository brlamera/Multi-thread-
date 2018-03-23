/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:45:19 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 11:13:44 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int rest;
	int i;

	rest = 0;
	n = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		n = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + (str[i] - '0');
		i++;
	}
	if (n == 1)
		return (-rest);
	return (rest);
}
