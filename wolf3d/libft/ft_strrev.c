/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:48:19 by aancel            #+#    #+#             */
/*   Updated: 2016/11/15 10:58:22 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		a;
	char	*dst;

	a = 0;
	i = ft_strlen(str);
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (dst[a])
	{
		dst[a] = str[i];
		a++;
		i--;
	}
	dst[a] = '\0';
	return (dst);
}
