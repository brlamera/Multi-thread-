/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pix_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:38:57 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 23:43:53 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	mlx_pix_put(t_img *img, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		img->bts[(y * img->size_line)
			+ ((img->bpp / 8) * x) + 2] = r;
		img->bts[(y * img->size_line)
			+ ((img->bpp / 8) * x) + 1] = g;
		img->bts[(y * img->size_line)
			+ ((img->bpp / 8) * x)] = b;
	}
}

void	mlx_pix_img(t_ptr *ptr, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 2] = r;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 1] = g;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x)] = b;
	}
}

void	mlx_textur(t_ptr *ptr, int x, t_ptd wall, int line)
{
	int		y;
	t_pti	text;

	y = ptr->y0;
	text.x = (int)(wall.x * ptr->txt->x);
	text.y = (int)((ptr->y0 - wall.y) * ptr->txt->y / line);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x) + 2] = ptr->txt->bts[(text.y *
			ptr->txt->size_line) + ((ptr->txt->bpp / 8) * text.x) + 2];
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x) + 1] = ptr->txt->bts[(text.y *
			ptr->txt->size_line) + ((ptr->txt->bpp / 8) * text.x) + 1];
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x)] = ptr->txt->bts[(text.y *
			ptr->txt->size_line) + ((ptr->txt->bpp / 8) * text.x)];
	}
}

void	mlx_img_copy(t_ptr *ptr, int x, int y, t_pti dec)
{
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x) + 2] = ptr->sky->bts[((y + dec.y) *
			ptr->sky->size_line) + ((ptr->sky->bpp / 8) * (x + dec.x)) + 2];
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x) + 1] = ptr->sky->bts[((y + dec.y) *
			ptr->sky->size_line) + ((ptr->sky->bpp / 8) * (x + dec.x)) + 1];
		ptr->img->bts[(y * ptr->img->size_line) +
			((ptr->img->bpp / 8) * x)] = ptr->sky->bts[((y + dec.y) *
			ptr->sky->size_line) + ((ptr->sky->bpp / 8) * (x + dec.x))];
	}
}

void	mlx_clr_img(t_ptr *ptr)
{
	int		x;
	int		y;
	t_pti	dec;

	dec.x = ptr->dec_x % ptr->sky->x;
	dec.y = ptr->dec_y - (ptr->key->crouch * ptr->crouch / 2);
	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			if (ptr->key->map)
				mlx_pix_img(ptr, x, y, 0x00404040);
			else if (y <= SIZE_Y / 2 + 10 && ptr->menu->skb)
				mlx_img_copy(ptr, x, y, dec);
			else
				mlx_pix_img(ptr, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}
