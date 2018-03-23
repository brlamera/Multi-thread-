/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:43:54 by aancel            #+#    #+#             */
/*   Updated: 2016/11/22 22:50:08 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	**ft_create_tab(int i, int j)
{
	char	**dst;

	if (!(dst = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (i >= 0)
	{
		if (!(dst[i] = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		ft_memset(dst[i], '\0', j + 1);
		i--;
	}
	return (dst);
}
