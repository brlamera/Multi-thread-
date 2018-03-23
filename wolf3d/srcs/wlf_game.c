/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:46:22 by brlaera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		game_loop(t_ptr *ptr)
{
	if (ptr->key->chg == 0)
		system("afplay file/gamecube.mp3 &");
	if (ptr->key->chg <= 17)
	{
		aff_charge(ptr->key->chg, ptr);
		if (ptr->key->chg == 17)
			usleep(650000);
		else if (ptr->key->chg < 9)
			usleep(100000);
		else
			usleep(300000);
		ptr->key->chg += 1;
		return (0);
	}
	if (ptr->key->chg == 18)
	{
		system("afplay file/castle.mp3 &");
		aff_choice(ptr);
		ptr->key->chg += 1;
	}
	game_loop2(ptr);
	return (0);
}

int		game_loop2(t_ptr *ptr)
{
	if (ptr->key->chg > 18)
	{
		ptr->movespeed = (ptr->key->sprint ? SPEED_DEF * 2 : SPEED_DEF);
		ptr->movespeed = (ptr->key->crouch ? SPEED_DEF / 2 : ptr->movespeed);
		if (ptr->key->up && !ptr->key->map)
			wlf_move('N', ptr);
		if (ptr->key->down && !ptr->key->map)
			wlf_move('S', ptr);
		if (ptr->key->left && !ptr->key->map)
			wlf_rot('W', ptr);
		if (ptr->key->right && !ptr->key->map)
			wlf_rot('E', ptr);
		if (ptr->key->esc)
			wlf_close();
		if (ptr->key->map)
			wlf_map(ptr);
		else
		{
			ptr->dec_x += -1 * ptr->menu->skbmv;
			wlf_aff_rendu(ptr);
		}
	}
	return (0);
}

int		wlf_move(char k, t_ptr *ptr)
{
	int dir;

	if (k == 'N' || k == 'S')
	{
		dir = (k == 'N' ? 1 : -1);
		if (ptr->map->map[(int)ptr->y_player][(int)(ptr->x_player +
			(dir * ptr->vec_x * ptr->movespeed) + dir * 0.2 * ptr->vec_x)] != 1)
			ptr->x_player += (ptr->vec_x * ptr->movespeed) * dir;
		if (ptr->map->map[(int)(ptr->y_player + (dir * ptr->vec_y *
			ptr->movespeed) + dir * 0.2 * ptr->vec_y)][(int)ptr->x_player] != 1)
			ptr->y_player += (ptr->vec_y * ptr->movespeed) * dir;
		if (ptr->dec_x1 == 1)
			ptr->dec_x1 = (ptr->dec_y1 >= 10 ? -1 : 1);
		else
			ptr->dec_x1 = (ptr->dec_y1 <= -10 ? 1 : -1);
		ptr->dec_y -= (ptr->key->sprint + 1) * ptr->dec_x1;
		ptr->dec_y1 += (ptr->key->sprint + 1) * 2 * ptr->dec_x1;
	}
	return (0);
}

int		wlf_rot(char k, t_ptr *ptr)
{
	double	olddirx;
	double	oldplanex;
	int		dir;

	if (k == 'W' || k == 'E')
	{
		dir = (k == 'W' ? 1 : -1);
		olddirx = ptr->vec_x;
		oldplanex = ptr->x_ecran;
		ptr->vec_x = ptr->vec_x * cos(ptr->rotspeed * dir) - ptr->vec_y
		* sin(ptr->rotspeed * dir);
		ptr->vec_y = olddirx * sin(ptr->rotspeed * dir)
		+ ptr->vec_y * cos(ptr->rotspeed * dir);
		ptr->x_ecran = ptr->x_ecran * cos(ptr->rotspeed * dir)
		- ptr->y_ecran * sin(ptr->rotspeed * dir);
		ptr->y_ecran = oldplanex * sin(ptr->rotspeed * dir)
		+ ptr->y_ecran * cos(ptr->rotspeed * dir);
		ptr->dec_x -= (dir * 50);
	}
	return (0);
}

double	wlf_spawn(char c, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->c)
	{
		j = 0;
		while (j < map->l)
		{
			if (map->map[j][i] == 5)
			{
				if (c == 'x')
					return (i + 0.5);
				if (c == 'y')
					return (j + 0.5);
			}
			j++;
		}
		i++;
	}
	return (ft_error(4));
}
