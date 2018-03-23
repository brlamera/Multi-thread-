/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:53:48 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 13:33:03 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		a;
	char	*dest;

	if (!s || !f)
		return (NULL);
	i = 0;
	a = ft_strlen(s);
	if (!(dest = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	while (i < a)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
