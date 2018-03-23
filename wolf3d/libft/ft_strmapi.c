/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:10:20 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 13:32:25 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
