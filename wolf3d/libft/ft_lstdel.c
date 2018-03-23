/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 22:14:12 by aancel            #+#    #+#             */
/*   Updated: 2016/11/16 08:18:56 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *t1;
	t_list *t2;

	t1 = *alst;
	while (t1 != NULL)
	{
		t2 = t1->next;
		del(t1->content, t1->content_size);
		free(t1);
		t1 = t2;
	}
	*alst = NULL;
}
