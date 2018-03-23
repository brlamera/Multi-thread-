/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:20:05 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 14:48:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	bfr;
	size_t	keep;
	size_t	i;

	i = 0;
	bfr = 0;
	keep = 0;
	while (s[bfr] == ' ' || s[bfr] == '\t' || s[bfr] == '\n')
		bfr++;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			i++;
			keep = i;
		}
		else
			i++;
	}
	if (keep == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, bfr, (keep - bfr)));
}
