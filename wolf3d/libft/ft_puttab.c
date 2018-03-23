/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:44:48 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 14:07:47 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_puttab(char **tab, int elem)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] && tab[i][0] != '\0' && i < elem)
	{
		ft_putnbr(i);
		ft_putstr(":\t[");
		ft_putstr(tab[i]);
		ft_putendl("]");
		i++;
	}
}
