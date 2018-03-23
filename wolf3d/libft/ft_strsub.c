/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:40:15 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 13:26:59 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start + len > i)
		return (NULL);
	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
	{
		dst[i] = s[start + i];
		len--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
