/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 16:30:31 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 14:45:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int u;

	u = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0')
	{
		dest[i] = src[u];
		i++;
		u++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}
