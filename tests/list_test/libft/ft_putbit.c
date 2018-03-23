/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:06:13 by juthomas          #+#    #+#             */
/*   Updated: 2016/03/10 18:30:24 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_bit(int i, char c)
{
	if (i > 0)
		print_bit(i - 1, c / 2);
	if (i == 4)
		ft_putchar(' ');
	ft_putchar(c % 2 + 48);
}

void			ft_putbit(char c)
{
	print_bit(7, c);
	ft_putchar('\n');
}
