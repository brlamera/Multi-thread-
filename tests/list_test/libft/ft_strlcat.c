/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 16:45:08 by juthomas          #+#    #+#             */
/*   Updated: 2016/01/30 02:22:42 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int u;
	unsigned int y;
	unsigned int z;

	i = 0;
	u = 0;
	y = 0;
	z = 0;
	while (dest[u] != '\0')
		u++;
	while (src[i] != '\0')
		i++;
	if (u > size)
		return (u + i - (u - size));
	y = u;
	while (src[z] != '\0' && y + 1 < size)
	{
		dest[y] = src[z];
		y++;
		z++;
	}
	dest[y] = '\0';
	return ((unsigned int)(u + i));
}
