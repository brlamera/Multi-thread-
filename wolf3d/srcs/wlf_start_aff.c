/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_start_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:44:01 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	set_color(t_ptr *ptr)
{
	if (ptr->key->c == 0)
	{
		ptr->n = 0x00FFFF00;
		ptr->s = 0x00FF0000;
		ptr->e = 0x0000FF00;
		ptr->w = 0x000000FF;
	}
	else
	{
		ptr->n = 0x00FF9933;
		ptr->s = 0x00CF5048;
		ptr->e = 0x00339933;
		ptr->w = 0x000066FF;
	}
}

void	draw_vis(t_ptr *ptr)
{
	t_pti a;

	a.x = 639 + SIZE_X / 2 - ptr->vis1->x / 2;
	a.y = 200 + SIZE_Y - ptr->vis1->y;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->vis1->ptr_img, a.x, a.y);
	mlx_put_image_to_window(ptr->mlx, ptr->win,
		ptr->vis3->ptr_img, 639 + 5, 200 - 40);
}

int		mlx_aff_point(int x, int y, t_ptr *ptr, int color)
{
	int a;
	int b;
	int size;

	size = ptr->sz;
	a = x - size;
	while (a <= x + size)
	{
		b = y - size;
		while (b <= y + size)
		{
			mlx_pix_img(ptr, a, b, color);
			b++;
		}
		a++;
	}
	return (0);
}

void	aff_charge(int i, t_ptr *ptr)
{
	char	*filename;
	t_file	*charg;

	charg = (t_file *)malloc(sizeof(t_file));
	if (!(filename = name(i)))
		wlf_close();
	charg->ptr_img = mlx_xpm_file_to_image(ptr->mlx, filename,
		&charg->x, &charg->y);
	charg->bts = mlx_get_data_addr(charg->ptr_img,
		&(charg->bpp), &(charg->size_line), &(charg->end));
	mlx_put_image_to_window(ptr->mlx, ptr->win,
		charg->ptr_img, MENU_X / 2 - charg->x / 2, MENU_Y / 2 - charg->y / 2);
	free(charg);
}

void	wlf_aff_map(t_map *m)
{
	t_ptr	*ptr;
	t_img	img;

	ptr = (t_ptr *)malloc(sizeof(t_ptr));
	ptr->map = m;
	if (!(ptr->mlx = mlx_init()))
		ft_error(3);
	ptr->win = mlx_new_window(ptr->mlx, MENU_X, MENU_Y, "Wolf3D");
	img.ptr_img = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	img.bts = mlx_get_data_addr(img.ptr_img, &(img.bpp),
		&(img.size_line), &(img.end));
	ptr->img = &img;
	init_menu(ptr);
	wlf_set_env(ptr);
	mlx_mouse_hook(ptr->win, mouse_code, ptr);
	mlx_hook(ptr->win, 17, (1L << 17), wlf_close, NULL);
	mlx_hook(ptr->win, 2, (1L << 0), key_press, ptr);
	mlx_hook(ptr->win, 3, (1L << 1), key_release, ptr);
	mlx_loop_hook(ptr->mlx, game_loop, ptr);
	mlx_loop(ptr->mlx);
}
