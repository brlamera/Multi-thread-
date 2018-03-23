/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 06:04:00 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 11:38:50 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				a;
	unsigned int	b;
	char			*str;

	str = (char *)s;
	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] != c)
			b++;
		if (str[i] == c)
			a = i;
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	if (b == ft_strlen(str))
		return (NULL);
	return (&str[a]);
}
