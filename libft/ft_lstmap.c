/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:29:52 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/22 18:31:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*beg_list;

	list = NULL;
	while (lst)
	{
		tmp = (*f)(lst);
		if (list)
		{
			list->next = ft_lstnew(tmp->content, tmp->content_size);
			list = list->next;
		}
		else
		{
			beg_list = ft_lstnew(tmp->content, tmp->content_size);
			list = beg_list;
		}
		lst = lst->next;
	}
	return (beg_list);
}
