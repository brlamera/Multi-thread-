/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:16:12 by aancel            #+#    #+#             */
/*   Updated: 2016/11/07 09:22:11 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			d;
	unsigned char	*str;

	d = c;
	str = (unsigned char *)b;
	while (len)
	{
		str[0] = d;
		str++;
		len--;
	}
	return (b);
}
