/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:28:55 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 03:09:51 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmpi;

	i = ft_strlen((char *)s);
	tmpi = (char*)s;
	while (i != 0 && tmpi[i] != (char)c)
		i--;
	if (tmpi[i] == (char)c)
		return (&tmpi[i]);
	return (NULL);
}
