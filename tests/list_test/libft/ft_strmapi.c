/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 03:11:12 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 14:27:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*retour;
	unsigned int		i;

	i = 0;
	retour = NULL;
	retour = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!retour)
		return (NULL);
	while (s[i] != '\0')
	{
		retour[i] = (char)f(i, s[i]);
		i++;
	}
	retour[i] = '\0';
	return (retour);
}
