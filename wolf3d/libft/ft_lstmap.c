/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:05:55 by aancel            #+#    #+#             */
/*   Updated: 2016/11/16 08:13:56 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *adr;
	t_list *fin;

	adr = NULL;
	fin = NULL;
	while (lst != NULL)
	{
		if (fin == NULL)
		{
			fin = f(lst);
			adr = fin;
		}
		else
		{
			adr->next = f(lst);
			adr = adr->next;
		}
		lst = lst->next;
	}
	return (fin);
}
