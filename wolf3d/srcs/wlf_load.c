/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:43:56 by brlamera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

char	*name(int x)
{
	if (x == 0)
		return ("file/portal750xpm/750as.xpm");
	if (x == 1)
		return ("file/portal750xpm/750as1.xpm");
	if (x == 2)
		return ("file/portal750xpm/750as2.xpm");
	if (x == 3)
		return ("file/portal750xpm/750as3.xpm");
	if (x == 4)
		return ("file/portal750xpm/750as4.xpm");
	if (x == 5)
		return ("file/portal750xpm/750as5.xpm");
	if (x == 6)
		return ("file/portal750xpm/750as6.xpm");
	if (x == 7)
		return ("file/portal750xpm/750as7.xpm");
	if (x == 8)
		return ("file/portal750xpm/750as8.xpm");
	if (x >= 9 && x <= 17)
		return (name2(x));
	return (NULL);
}

char	*name2(int x)
{
	if (x == 9)
		return ("file/portal750xpm/750as9.xpm");
	if (x == 10)
		return ("file/portal750xpm/750as10.xpm");
	if (x == 11)
		return ("file/portal750xpm/750as11.xpm");
	if (x == 12)
		return ("file/portal750xpm/750as12.xpm");
	if (x == 13)
		return ("file/portal750xpm/750as13.xpm");
	if (x == 14)
		return ("file/portal750xpm/750as14.xpm");
	if (x == 15)
		return ("file/portal750xpm/750as15.xpm");
	if (x == 16)
		return ("file/portal750xpm/750as16.xpm");
	if (x == 17)
		return ("file/portal750xpm/750as16.xpm");
	return (NULL);
}

void	loading_file(t_ptr *ptr)
{
	t_file	*vis1;
	t_file	*vis2;
	t_file	*vis3;

	vis1 = (t_file *)malloc(sizeof(t_file));
	if (!(vis1->ptr_img = mlx_xpm_file_to_image(ptr->mlx, "file/arme2.xpm",
		&vis1->x, &vis1->y)))
		ft_error(5);
	vis1->bts = mlx_get_data_addr(vis1->ptr_img, &(vis1->bpp),
		&(vis1->size_line), &(vis1->end));
	ptr->vis1 = vis1;
	vis2 = (t_file *)malloc(sizeof(t_file));
	if (!(vis2->ptr_img = mlx_xpm_file_to_image(ptr->mlx, "file/aknila3.xpm",
		&vis2->x, &vis2->y)))
		ft_error(5);
	vis2->bts = mlx_get_data_addr(vis2->ptr_img, &(vis2->bpp),
		&(vis2->size_line), &(vis2->end));
	ptr->vis2 = vis2;
	vis3 = (t_file *)malloc(sizeof(t_file));
	if (!(vis3->ptr_img = mlx_xpm_file_to_image(ptr->mlx, "file/lifebar.xpm",
		&vis3->x, &vis3->y)))
		ft_error(5);
	vis3->bts = mlx_get_data_addr(vis3->ptr_img, &(vis3->bpp),
		&(vis2->size_line), &(vis3->end));
	ptr->vis3 = vis3;
}

void	aff_choice(t_ptr *ptr)
{
	t_menu	*choice;
	t_file	*aff;
	char	*fl;

	aff = (t_file *)malloc(sizeof(t_file));
	choice = ptr->menu;
	mlx_put_image_to_window(ptr->mlx, ptr->win, choice->menu->ptr_img, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->vis2->ptr_img,
		MENU_X - ptr->vis2->x, 0);
	if (choice->skbsel == 1)
		fl = "file/menudesignxpm/sky1.xpm";
	else if (choice->skbsel == 2)
		fl = "file/menudesignxpm/sky2.xpm";
	else if (choice->skbsel == 3)
		fl = "file/menudesignxpm/sky3.xpm";
	else
		fl = "file/menudesignxpm/sky4.xpm";
	ptr->dec_y = (choice->skbsel == 4 ? 100 : 50);
	if (!(aff->ptr_img = mlx_xpm_file_to_image(ptr->mlx, fl, &aff->x, &aff->y)))
		ft_error(5);
	aff->bts = mlx_get_data_addr(aff->ptr_img, &(aff->bpp),
		&(aff->size_line), &(aff->end));
	mlx_put_image_to_window(ptr->mlx, ptr->win, aff->ptr_img, 180, 500);
	free(aff);
	aff_choice2(ptr);
}

void	aff_choice2(t_ptr *ptr)
{
	t_menu	*choice;
	t_file	*aff;
	char	*fl;

	aff = (t_file *)malloc(sizeof(t_file));
	choice = ptr->menu;
	if (choice->skb == 1)
		fl = "file/menudesignxpm/up-on.xpm";
	else
		fl = "file/menudesignxpm/up-off.xpm";
	if (!(aff->ptr_img = mlx_xpm_file_to_image(ptr->mlx, fl, &aff->x, &aff->y)))
		ft_error(5);
	aff->bts = mlx_get_data_addr(aff->ptr_img, &(aff->bpp),
		&(aff->size_line), &(aff->end));
	mlx_put_image_to_window(ptr->mlx, ptr->win, aff->ptr_img, -20, 150);
	if (choice->skbmv == 1)
		fl = "file/menudesignxpm/down-on.xpm";
	else
		fl = "file/menudesignxpm/down-off.xpm";
	if (!(aff->ptr_img = mlx_xpm_file_to_image(ptr->mlx, fl, &aff->x, &aff->y)))
		ft_error(5);
	aff->bts = mlx_get_data_addr(aff->ptr_img, &(aff->bpp),
		&(aff->size_line), &(aff->end));
	mlx_put_image_to_window(ptr->mlx, ptr->win, aff->ptr_img, -20, 150);
	free(aff);
}
