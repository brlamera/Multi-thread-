/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:41:38 by aancel            #+#    #+#             */
/*   Updated: 2016/11/20 10:50:29 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*csrc;
	unsigned char	a;

	a = (unsigned char)c;
	csrc = (unsigned char *)src;
	str = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		str[i] = csrc[i];
		if (csrc[i] == a)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
