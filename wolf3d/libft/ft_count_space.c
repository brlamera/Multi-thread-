/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:09:00 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 11:30:25 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_count_space(char const *str)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		a++;
		i++;
	}
	i = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		a++;
		i--;
	}
	return (a);
}
