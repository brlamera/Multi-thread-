/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:44:48 by aancel            #+#    #+#             */
/*   Updated: 2016/11/20 10:50:53 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_puttab_fd(char **tab, int elem, int fd)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] && tab[i][0] != '\0' && i < elem)
	{
		ft_putnbr_fd(i, fd);
		ft_putstr_fd(":\t[", fd);
		ft_putstr_fd(tab[i], fd);
		ft_putendl_fd("]", fd);
		i++;
	}
}
