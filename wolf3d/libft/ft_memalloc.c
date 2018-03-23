/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 03:15:48 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 12:22:19 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char			*dst;
	unsigned int	i;

	if (!(dst = malloc(size)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
