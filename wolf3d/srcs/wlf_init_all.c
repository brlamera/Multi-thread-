/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_init_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:43:55 by brlamera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_text(t_file *txt, t_ptr *ptr)
{
	char *filename;

	if (ptr->texture == 1)
		filename = "file/texture1.xpm";
	else if (ptr->texture == 2)
		filename = "file/mario_block.xpm";
	else if (ptr->texture == 3)
		filename = "file/nicolas_cage.xpm";
	else if (ptr->texture == 4)
		filename = "file/didier.xpm";
	else
		filename = "file/pushtotalk.xpm";
	if (!(txt->ptr_img = mlx_xpm_file_to_image(ptr->mlx, filename, &txt->x,
		&txt->y)))
		ft_error(5);
	txt->bts = mlx_get_data_addr(txt->ptr_img, &(txt->bpp),
		&(txt->size_line), &(txt->end));
}

void	init_skybox(t_file *sky, t_ptr *ptr)
{
	char *filename;

	if (ptr->menu->skbsel == 1)
		filename = "file/air-skybox.xpm";
	else if (ptr->menu->skbsel == 2)
		filename = "file/skybox.xpm";
	else if (ptr->menu->skbsel == 3)
		filename = "file/nian_trump1.xpm";
	else
		filename = "file/skynight.xpm";
	if (!(sky->ptr_img = mlx_xpm_file_to_image(ptr->mlx, filename,
		&sky->x, &sky->y)))
		ft_error(5);
	sky->bts = mlx_get_data_addr(sky->ptr_img, &(sky->bpp),
		&(sky->size_line), &(sky->end));
}

void	init_menu(t_ptr *ptr)
{
	t_file	*mn;
	t_menu	*menu1;
	char	*str;

	str = "file/menudesignxpm/menu.xpm";
	menu1 = (t_menu *)malloc(sizeof(t_menu));
	mn = (t_file *)malloc(sizeof(t_file));
	if (!(mn->ptr_img = mlx_xpm_file_to_image(ptr->mlx, str, &mn->x, &mn->y)))
		ft_error(5);
	mn->bts = mlx_get_data_addr(mn->ptr_img, &(mn->bpp),
		&(mn->size_line), &(mn->end));
	menu1->menu = mn;
	menu1->skb = 1;
	menu1->skbsel = 1;
	menu1->skbmv = 1;
	ptr->menu = menu1;
}

void	init_key(t_key *key)
{
	key->down = 0;
	key->up = 0;
	key->left = 0;
	key->right = 0;
	key->sprint = 0;
	key->crouch = 0;
	key->esc = 0;
	key->c = 0;
	key->chg = 0;
	key->menu = 0;
	key->enter = 0;
	key->map = 0;
}

void	wlf_initialis(t_ptr *ptr)
{
	ptr->vec_x = -0.5;
	ptr->vec_y = 0;
	ptr->x_player = wlf_spawn('x', ptr->map);
	ptr->y_player = wlf_spawn('y', ptr->map);
	ptr->x_ecran = 0;
	ptr->y_ecran = 0.66;
	ptr->size_x = SIZE_X;
	ptr->size_y = SIZE_Y;
	ptr->movespeed = 0.3;
	ptr->rotspeed = 0.1;
	ptr->n = 0x00FFFF00;
	ptr->s = 0x00FF0000;
	ptr->e = 0x0000FF00;
	ptr->w = 0x000000FF;
	ptr->dec_x = 0;
	ptr->dec_y = 10;
	ptr->dec_x1 = 1;
	ptr->dec_y1 = 0;
	ptr->crouch = -100;
	ptr->texture = 1;
	ptr->sz = 7;
}
