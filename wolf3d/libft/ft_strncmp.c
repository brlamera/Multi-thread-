/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:43:20 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 11:16:09 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i]
			&& i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
