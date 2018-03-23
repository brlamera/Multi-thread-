/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:39:51 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/10 16:48:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_strsplit_mots(unsigned int i, unsigned int nbr,
		const char *s, char c)
{
	nbr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			nbr++;
		}
	}
	return (nbr);
}

static char				**ft_strsplit_part2(unsigned int p[3],
		char **tab, char const *s, char c)
{
	while (s[p[1]] != '\0')
	{
		while (s[p[1]] == c && s[p[1]] != '\0')
			p[1]++;
		if (s[p[1]] != '\0' && s[p[1]] != c)
		{
			p[0] = p[1];
			while (s[p[1]] != '\0' && s[p[1]] != c)
				p[1]++;
			if ((tab[p[2]] = (char*)malloc(sizeof(char) *
							(p[1] - p[0] + 1))) == NULL)
				return (NULL);
			p[1] = p[0];
			while (s[p[1]] != '\0' && s[p[1]] != c)
			{
				tab[p[2]][p[1] - p[0]] = s[p[1]];
				p[1]++;
			}
			tab[p[2]][p[1] - p[0]] = '\0';
			p[2]++;
		}
	}
	tab[p[2]] = NULL;
	return (tab);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	p[3];

	p[1] = 0;
	p[2] = 0;
	p[2] = ft_strsplit_mots(p[1], p[2], s, c);
	if ((tab = (char**)malloc(sizeof(char*) * (p[2] + 1))) == NULL)
		return (NULL);
	p[1] = 0;
	p[2] = 0;
	tab = ft_strsplit_part2(p, tab, s, c);
	return (tab);
}
