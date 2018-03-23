/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:50:34 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 17:28:16 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(char *big, char *little)
{
	int i;
	int a;
	int n;

	i = 0;
	if (little[i] == '\0')
		return (big);
	while (big[i])
	{
		a = i;
		n = 0;
		while (big[i] == little[n])
		{
			if (little[n])
			{
				i++;
				n++;
			}
			if (little[n] == '\0')
				return (&big[a]);
		}
		i = a;
		i++;
	}
	return (NULL);
}
