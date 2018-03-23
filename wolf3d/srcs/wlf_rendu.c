/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_rendu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:44:00 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		wlf_final_aff(t_ptr *ptr)
{
	if (ptr->key->enter)
		wlf_minimap(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 639, 200);
	draw_vis(ptr);
}

static void		wlf_draw_texture(t_rend e, t_ptr *ptr)
{
	while (ptr->y0 <= SIZE_Y)
	{
		if (ptr->y0 < ptr->y1 && ptr->y0 >= 0)
		{
			if (ptr->texture != 0)
				mlx_textur(ptr, e.x, e.wall, e.lineh);
			else
				mlx_pix_img(ptr, e.x, ptr->y0, ptr->colors);
		}
		else
			mlx_pix_img(ptr, e.x, ptr->y0, 0x00808080);
		ptr->y0 += 1;
	}
}

static void		wlf_draw(t_rend e, t_ptr *ptr)
{
	e.wdist = (!e.side ? (e.map.x - e.rpos.x + (1 - e.step.x) / 2) / e.rdir.x :
		(e.map.y - e.rpos.y + (1 - e.step.y) / 2) / e.rdir.y);
	e.wall.x = (!e.side ? e.rpos.y + e.wdist * e.rdir.y :
		e.rpos.x + e.wdist * e.rdir.x);
	e.wall.x -= (int)(e.wall.x);
	e.lineh = (int)(SIZE_Y / e.wdist);
	e.drawst = -e.lineh / 2 + SIZE_Y / 2;
	if (e.drawst + ptr->dec_y1 + (ptr->key->crouch * ptr->crouch) < 0
		&& ptr->texture == 0)
		e.drawst = -(ptr->dec_y1 + (ptr->key->crouch * ptr->crouch));
	e.drawend = e.lineh / 2 + SIZE_Y / 2;
	if (e.drawend + ptr->dec_y1 + (ptr->key->crouch * ptr->crouch) > SIZE_Y)
		e.drawend = SIZE_Y - (ptr->dec_y1 + (ptr->key->crouch * ptr->crouch));
	if (e.side == 0)
		ptr->colors = (e.step.x == -1 ? ptr->n : ptr->s);
	else
		ptr->colors = (e.step.y == -1 ? ptr->w : ptr->e);
	ptr->x0 = e.x;
	ptr->x1 = e.x;
	ptr->y0 = e.drawst + ptr->dec_y1 + (ptr->key->crouch * ptr->crouch);
	ptr->y1 = e.drawend + ptr->dec_y1 + (ptr->key->crouch * ptr->crouch);
	e.wall.y = ptr->y0;
	wlf_draw_texture(e, ptr);
}

static void		wlf_start_find(t_rend e, t_ptr *ptr)
{
	if (e.rdir.x < 0)
		e.fdist.x = (e.rpos.x - e.map.x) * e.ddist.x;
	else
		e.fdist.x = (e.map.x + 1 - e.rpos.x) * e.ddist.x;
	if (e.rdir.y < 0)
		e.fdist.y = (e.rpos.y - e.map.y) * e.ddist.y;
	else
		e.fdist.y = (e.map.y + 1 - e.rpos.y) * e.ddist.y;
	while (e.hit == 0)
	{
		e.side = (e.fdist.x < e.fdist.y ? 0 : 1);
		if (e.fdist.x < e.fdist.y)
		{
			e.fdist.x += e.ddist.x;
			e.map.x += e.step.x;
		}
		else
		{
			e.fdist.y += e.ddist.y;
			e.map.y += e.step.y;
		}
		if (ptr->map->map[e.map.y][e.map.x] == 1)
			e.hit = 1;
	}
	wlf_draw(e, ptr);
}

void			wlf_aff_rendu(t_ptr *ptr)
{
	t_rend	e;

	mlx_clr_img(ptr);
	e.dir.x = ptr->vec_x;
	e.dir.y = ptr->vec_y;
	e.x = 0;
	e.w = SIZE_X;
	while (e.x < e.w)
	{
		e.hit = 0;
		e.cam = 2 * (double)e.x / (double)e.w - 1;
		e.rpos.x = ptr->x_player;
		e.rpos.y = ptr->y_player;
		e.rdir.x = e.dir.x + ptr->x_ecran * e.cam;
		e.rdir.y = e.dir.y + ptr->y_ecran * e.cam;
		e.map.x = (int)e.rpos.x;
		e.map.y = (int)e.rpos.y;
		e.ddist.x = sqrt(1 + (e.rdir.y * e.rdir.y) / (e.rdir.x * e.rdir.x));
		e.ddist.y = sqrt(1 + (e.rdir.x * e.rdir.x) / (e.rdir.y * e.rdir.y));
		e.step.x = (e.rdir.x < 0 ? -1 : 1);
		e.step.y = (e.rdir.y < 0 ? -1 : 1);
		wlf_start_find(e, ptr);
		e.x++;
	}
	wlf_final_aff(ptr);
}
