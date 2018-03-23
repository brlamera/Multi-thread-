/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:50:56 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 14:48:51 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	int		i;

	cpy = NULL;
	i = ft_strlen(s1) + ft_strlen(s2);
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, s1);
	cpy = ft_strcat(cpy, s2);
	return (cpy);
}
