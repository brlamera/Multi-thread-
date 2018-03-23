/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 05:04:05 by aancel            #+#    #+#             */
/*   Updated: 2016/11/23 12:46:43 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	while (dst[i] && i < size)
		i++;
	a = i;
	while (src[i - a] && (i + 1) < size)
	{
		dst[i] = src[i - a];
		i++;
	}
	if (a < size)
		dst[i] = '\0';
	return (a + ft_strlen(src));
}
