/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:17:33 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 13:22:24 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		i;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (a + b + 1))))
		return (NULL);
	while (i < a)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < b)
	{
		dest[i + a] = s2[i];
		i++;
	}
	dest[i + a] = '\0';
	return (dest);
}
