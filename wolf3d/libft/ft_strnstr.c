/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:21:24 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 17:48:06 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(char *big, char *little, size_t loc)
{
	size_t		i;
	size_t		a;
	size_t		n;

	i = 0;
	n = 0;
	if (little[i] == '\0')
		return (big);
	while (big[i] && i < loc)
	{
		a = i;
		while (big[a] == little[n] && little[n] && n < loc)
		{
			a++;
			n++;
		}
		if (little[n] == '\0' && a - 1 < loc)
			return (&big[i]);
		else if (n > loc)
			return (NULL);
		else
			n = 0;
		i++;
	}
	return (NULL);
}
