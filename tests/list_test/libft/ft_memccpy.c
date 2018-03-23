/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:33:27 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/22 14:04:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	unsigned int		u;
	unsigned char		*cpy1;
	unsigned char		*cpy2;
	unsigned char		v;

	v = (unsigned char)c;
	u = 0;
	cpy1 = (unsigned char*)dst;
	cpy2 = (unsigned char*)src;
	while (u < n)
	{
		cpy1[u] = cpy2[u];
		if (cpy1[u] == v)
			return ((void *)&cpy1[u + 1]);
		u++;
	}
	return (NULL);
}
