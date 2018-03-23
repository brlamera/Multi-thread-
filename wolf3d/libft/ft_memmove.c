/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:14:40 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 16:39:25 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	tmp[len];
	unsigned int	i;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (len >= 128 * 1024 * 1024)
		return (NULL);
	while (i < len)
	{
		tmp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst2[i] = tmp[i];
		i++;
	}
	return (dst);
}
