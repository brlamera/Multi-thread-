/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:52:12 by aancel            #+#    #+#             */
/*   Updated: 2016/11/22 23:05:04 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char		**ft_tab(char **dst, char const *s, char c)
{
	int		j;
	int		i;
	int		k;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			k = i;
			while (s[i] != c && s[i])
				i++;
			dst[j] = ft_strsub(s, k, (i - k));
			j++;
		}
	}
	dst[j] = NULL;
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		word;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	dst = ft_tab(dst, s, c);
	return (dst);
}
