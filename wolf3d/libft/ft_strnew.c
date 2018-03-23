/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:25:18 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 11:39:16 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
