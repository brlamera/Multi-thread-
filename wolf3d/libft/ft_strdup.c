/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:29:14 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 16:34:05 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(src);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
