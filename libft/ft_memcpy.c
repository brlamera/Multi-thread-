/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 17:51:12 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/22 14:03:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int		u;
	char				*cpy1;
	const char			*cpy2;

	u = 0;
	cpy1 = (char*)dst;
	cpy2 = (const char*)src;
	while (u < n)
	{
		cpy1[u] = cpy2[u];
		u++;
	}
	return ((void *)cpy1);
}
