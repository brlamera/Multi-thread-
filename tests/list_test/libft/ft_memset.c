/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 17:42:03 by juthomas          #+#    #+#             */
/*   Updated: 2016/01/30 02:22:39 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*cpy;

	cpy = b;
	i = 0;
	while (i < len)
	{
		cpy[i] = c;
		i++;
	}
	b = cpy;
	return (b);
}
