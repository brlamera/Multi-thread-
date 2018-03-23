/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:59:03 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 12:20:43 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*csrc;

	csrc = (unsigned char *)src;
	str = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		str[i] = csrc[i];
		i++;
	}
	return (dst);
}
