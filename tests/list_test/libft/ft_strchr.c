/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:49:35 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 03:02:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i] != (char)c && (char)s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char*)&s[i]);
	return ((char*)0);
}
