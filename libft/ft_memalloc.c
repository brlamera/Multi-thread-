/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@ssh.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:12:02 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/10 23:57:16 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (ret != NULL)
	{
		ft_bzero(ret, size);
		return (ret);
	}
	return (NULL);
}
