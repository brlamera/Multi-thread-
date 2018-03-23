/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:27:30 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/11 02:47:00 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = *alst;
	while (cpy)
	{
		tmp = cpy->next;
		ft_lstdelone(&cpy, del);
		cpy = tmp;
	}
	*alst = NULL;
}
