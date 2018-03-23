/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 23:07:54 by brlamera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "color.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define SIZE_X 1350
# define SIZE_Y 900
# define MENU_X 2048
# define MENU_Y 1152
# define CASE_X 25
# define CASE_Y 25
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define RAD(x) PI * x / 180
# define PI M_PI
# define MAX_FPS 60
# define SPEED_DEF 0.3

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		err;
	int		sx;
	int		sy;
	int		e2;
}				t_line;

typedef struct	s_stc
{
	int			n;
	int			s;
	int			i;
	char		*str;
}				t_stc;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_file
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
	int			x;
	int			y;
}				t_file;

typedef struct	s_map
{
	int			l;
	int			c;
	int			**map;
}				t_map;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef	struct	s_ptd
{
	double		x;
	double		y;
}				t_ptd;

typedef	struct	s_pti
{
	int			x;
	int			y;
}				t_pti;

typedef struct	s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			sprint;
	int			crouch;
	int			esc;
	int			c;
	int			menu;
	int			chg;
	int			enter;
	int			map;
}				t_key;

typedef struct	s_mini
{
	int			a;
	int			b;
	int			i;
	int			j;
	int			i2;
	int			j2;
	int			sz;
	int			di;
	int			dj;
}				t_mini;

typedef struct	s_rend
{
	t_ptd		dir;
	int			x;
	int			w;
	double		cam;
	t_ptd		rpos;
	t_ptd		rdir;
	t_pti		map;
	t_ptd		fdist;
	t_ptd		ddist;
	t_pti		step;
	t_ptd		wall;
	int			hit;
	int			side;
	double		wdist;
	int			lineh;
	int			drawst;
	int			drawend;
}				t_rend;

typedef struct	s_menu
{
	int			skb;
	int			skbsel;
	int			skbmv;
	t_file		*menu;
}				t_menu;

typedef struct	s_ptr
{
	t_map		*map;
	t_img		*img;
	t_img		*minimap;
	t_menu		*menu;
	t_vec		*vec;
	t_file		*sky;
	t_key		*key;
	t_file		*vis1;
	t_file		*vis2;
	t_file		*vis3;
	t_file		*txt;
	int			texture;
	double		cam;
	double		x_ecran;
	double		y_ecran;
	double		x_player;
	double		y_player;
	double		dis;
	double		a;
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			colors;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			n;
	int			s;
	int			w;
	int			e;
	double		vec_x;
	double		vec_y;
	int			dec_x;
	int			dec_y;
	int			dec_x1;
	int			dec_y1;
	int			crouch;
	double		movespeed;
	double		rotspeed;
	int			sz;
}				t_ptr;

void			aff_charge(int i, t_ptr *ptr);
void			aff_choice(t_ptr *ptr);
void			aff_choice2(t_ptr *ptr);
void			aff_menu(t_ptr *ptr);
void			draw_vis(t_ptr *ptr);
int				ft_count_s(char *str);
int				ft_error(int error);
int				ft_isfullnum(char *str);
char			*ft_strjoin_free(char *s1, char *s2);
int				game_loop(t_ptr *ptr);
int				game_loop2(t_ptr *ptr);
void			init_key(t_key	*key);
void			init_map(t_map *map, t_ptr *ptr);
void			init_menu(t_ptr *ptr);
void			init_skybox(t_file *sky, t_ptr *ptr);
void			init_text(t_file *txt, t_ptr *ptr);
int				key_press(int k, t_ptr *ptr);
int				key_press2(int k, t_ptr *ptr);
int				key_release(int k, t_ptr *ptr);
void			loading_file(t_ptr *ptr);
int				main(int argc, char **argv);
int				mlx_aff_point(int x, int y, t_ptr *ptr, int color);
void			mlx_clr_img(t_ptr *ptr);
void			mlx_img_copy(t_ptr *ptr, int x, int y, t_pti dec);
void			mlx_pix_img(t_ptr *ptr, int x, int y, int color);
void			mlx_pix_put(t_img *img, int x, int y, int color);
void			mlx_put_line(t_ptr *ptr);
void			mlx_textur(t_ptr *ptr, int x, t_ptd wall, int line);
int				mouse_code(int button, int x, int y, t_ptr *ptr);
int				mouse_code2(int x, int y, t_ptr *ptr);
char			*name(int x);
char			*name2(int x);
int				scnd_main(char *argv);
void			set_color(t_ptr *ptr);
void			set_menu(char id, t_img *img);
void			wlf_aff_map(t_map *m);
void			wlf_aff_rendu(t_ptr *ptr);
int				wlf_check_ext(char *str);
int				wlf_check_file(int *l, int *a, int fd);
int				wlf_check_file2(char **str1, int *l, int *a);
int				wlf_close(void);
void			wlf_draw_img(t_ptr *ptr);
char			*wlf_extracting(int fd);
void			wlf_initialis(t_ptr *ptr);
void			wlf_map(t_ptr *ptr);
void			wlf_map2(t_mini m, t_ptr *ptr);
t_map			*wlf_map_extract(int fd, char *filename);
void			wlf_minimap(t_ptr *ptr);
void			wlf_minimap2(t_mini mn, t_ptr *ptr);
void			wlf_minimap3(t_mini m, t_ptr *ptr);
int				wlf_move(char k, t_ptr *ptr);
int				**wlf_put_in_map(int **map, int fd, int my, int mx);
int				wlf_rot(char k, t_ptr *ptr);
void			wlf_set_env(t_ptr *ptr);
double			wlf_spawn(char c, t_map *map);

#endif
