/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:49:37 by aancel            #+#    #+#             */
/*   Updated: 2016/11/16 07:49:50 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *nouveau)
{
	if (alst != NULL && nouveau != NULL)
	{
		nouveau->next = *alst;
		*alst = nouveau;
	}
}
