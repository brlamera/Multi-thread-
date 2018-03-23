/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:45:21 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/22 18:37:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	if (!(*s1) && !(*s2))
		return ("");
	if (!(*s1))
		return (NULL);
	while (s2[0] && s1[i] && i < n)
	{
		tmp = 0;
		if (s1[i] == s2[0])
		{
			while (s1[i + tmp] == s2[tmp] && i + tmp < n && s2[tmp] != '\0'
					&& s1[i + tmp] != '\0')
				tmp++;
			if (s2[tmp] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
	}
	if (s2[tmp] == '\0' && (*s1))
		return ((char*)s1);
	return (NULL);
}
