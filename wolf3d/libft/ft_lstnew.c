/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:34:27 by aancel            #+#    #+#             */
/*   Updated: 2016/11/16 07:46:55 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p_list;

	if (!(p_list = malloc(sizeof(*p_list))))
		return (NULL);
	if (content == NULL)
	{
		p_list->content = NULL;
		p_list->content_size = 0;
	}
	else
	{
		if (!(p_list->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(p_list->content, content, content_size);
		p_list->content_size = content_size;
	}
	p_list->next = NULL;
	return (p_list);
}
