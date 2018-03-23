/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:31:08 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 14:36:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	cpy = (char*)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	while (i != len)
	{
		cpy[i] = s[i + start];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
