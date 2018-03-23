/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:43:58 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wlf_minimap(t_ptr *ptr)
{
	t_mini m;

	m.sz = ptr->sz * 2 + 2;
	m.a = 11 * m.sz + ptr->sz * 2;
	m.b = 11 * m.sz + ptr->sz * 2;
	m.i = SIZE_X - m.a - ptr->sz * 2;
	m.di = m.i + 1;
	while (m.i <= SIZE_X - m.sz)
	{
		m.j = SIZE_Y - m.b - ptr->sz * 2;
		m.dj = m.j + 1;
		while (m.j <= SIZE_Y - m.sz)
		{
			if (((m.i == m.di || m.i == SIZE_X - m.sz - 1) && (m.j >= m.dj &&
				m.j <= SIZE_Y - m.sz - 1)) || ((m.i >= m.di && m.i <= SIZE_X
				- m.sz - 1) && (m.j == m.dj || m.j == SIZE_Y - m.sz - 1)))
				mlx_pix_img(ptr, m.i, m.j, 0x00FFFFFF);
			else
				mlx_pix_img(ptr, m.i, m.j, 0x00404040);
			m.j++;
		}
		m.i++;
	}
	wlf_minimap2(m, ptr);
}

void	wlf_minimap2(t_mini m, t_ptr *ptr)
{
	m.a = SIZE_X - m.a;
	m.b = SIZE_Y - m.b;
	m.i = (int)ptr->y_player - 5;
	m.j = (int)ptr->x_player - 5;
	m.i2 = 0;
	while (m.i + m.i2 <= (int)ptr->y_player + 5)
	{
		m.j2 = 0;
		while (m.j + m.j2 <= (int)ptr->x_player + 5)
		{
			if (m.i + m.i2 >= 0 && m.j + m.j2 >= 0 && m.i + m.i2
				< ptr->map->l && m.j + m.j2 < ptr->map->c)
				wlf_minimap3(m, ptr);
			m.j2++;
		}
		m.i2++;
	}
}

void	wlf_minimap3(t_mini m, t_ptr *ptr)
{
	if (m.i + m.i2 == (int)ptr->y_player && m.j + m.j2 == (int)ptr->x_player)
		mlx_aff_point(m.i2 * m.sz + m.a, m.j2 * m.sz + m.b, ptr, 0x00FF0000);
	else if (ptr->map->map[m.i + m.i2][m.j + m.j2] == 1)
		mlx_aff_point(m.i2 * m.sz + m.a, m.j2 * m.sz + m.b, ptr, 0x0000C1D5);
	else if (ptr->map->map[m.i + m.i2][m.j + m.j2] == 2)
		mlx_aff_point(m.i2 * m.sz + m.a, m.j2 * m.sz + m.b, ptr, 0x00008FB7);
	else
		mlx_aff_point(m.i2 * m.sz + m.a, m.j2 * m.sz + m.b, ptr, 0x00000000);
}

void	wlf_map(t_ptr *ptr)
{
	t_mini m;

	ptr->sz = ((int)(SIZE_X / ptr->map->l / 3) < (int)(SIZE_Y / ptr->map->c / 3)
		? (int)(SIZE_X / ptr->map->l / 3) : (int)(SIZE_Y / ptr->map->c / 3));
	m.sz = ptr->sz * 2 + 2;
	m.a = SIZE_X / 2 - ptr->map->l * m.sz / 2;
	m.b = SIZE_Y / 2 - ptr->map->c * m.sz / 2;
	mlx_clr_img(ptr);
	m.i = 0;
	while (m.i < ptr->map->l)
	{
		m.j = 0;
		while (m.j < ptr->map->c)
		{
			wlf_map2(m, ptr);
			m.j++;
		}
		m.i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 639, 200);
	ptr->sz = 7;
}

void	wlf_map2(t_mini m, t_ptr *ptr)
{
	if (m.i == (int)ptr->y_player && m.j == (int)ptr->x_player)
		mlx_aff_point(m.i * m.sz + m.a, m.j * m.sz + m.b, ptr, 0x00FF0000);
	else if (ptr->map->map[m.i][m.j] == 1)
		mlx_aff_point(m.i * m.sz + m.a, m.j * m.sz + m.b, ptr, 0x00000000);
	else if (ptr->map->map[m.i][m.j] == 2)
		mlx_aff_point(m.i * m.sz + m.a, m.j * m.sz + m.b, ptr, 0x00008FB7);
	else
		mlx_aff_point(m.i * m.sz + m.a, m.j * m.sz + m.b, ptr, 0x00FFFFFF);
}
