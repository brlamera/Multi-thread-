/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:25:43 by aancel            #+#    #+#             */
/*   Updated: 2017/05/08 16:24:38 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char *s)
{
	size_t	st;
	size_t	end;
	char	*dst;

	st = 0;
	if (!s)
		return (NULL);
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (s[st] != '\0')
	{
		end = ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		end++;
		if (!(dst = (char *)malloc(sizeof(char) * (end - st))))
			return (NULL);
		dst = ft_strsub(s, st, end - st);
	}
	else
	{
		dst = (char *)malloc(sizeof(char) * 1);
		dst[0] = '\0';
	}
	return (dst);
}
