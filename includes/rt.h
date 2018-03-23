/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:23:54 by juthomas          #+#    #+#             */
/*   Updated: 2018/03/14 16:31:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line.h"
# include "./rt_obj.h"
# include "./rt_light.h"
//# define X_WIN 640
//# define Y_WIN 480

# define X_WIN 1200
# define Y_WIN 800
# define X_IMG X_WIN * 2
# define Y_IMG Y_WIN * 2
# define INFINI 200
# define NORM_COLOR 1
# define MAX_RAY_DEPTH 10
// NOMBRE DE REFLETS MAX

typedef struct		s_win
{
	int				bpp;
	int				bpp2;
	int				bpp3;

	int				sizeline;
	int				sizeline2;
	int				sizeline3;

	int				endian;
	int				endian2;
	int				endian3;


	void			*img;
	void			*img2;
	void			*img3;

	char			*addr;
	char			*addr2;
	char			*addr3;


	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_type
{
	void			*obj;
	char			name;
}					t_type;

typedef struct		s_scene
{
	struct s_vec	*cam_org;
	struct s_vec	*cam_rot;
	t_list			*cam;
	t_list			*light;
	t_list			*obj;
}					t_scene;

typedef struct		s_trace
{
	int		inter;
	t_spher	*spher;
	t_spher *sphere;
	t_lspher *lsphere;
	t_type	*type;
	float	t0;
	float	t1;
	t_vec	*surface_color;
	t_vec	*phit;
	t_vec	*nhit;
	float	tnear;
	short	inside;
	float	bias;
	float	facingratio;
	float	fresneleffect;
	t_vec	*refldir;
	t_vec	*reflection;
	t_vec	*refraction;
	float	ior;
	float	cosi;
	float	k;
	float	eta;
	t_vec	*refrdir;
	t_vec	*tmp_vec;
	unsigned int i;
	float	lumiere_inc;
	t_vec	*lum_inc;
	int		depth;
	int test;
}					t_trace;

typedef struct		s_render
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	y;
	unsigned int	x;
	unsigned int	z;
	unsigned int	x_tmp;
	unsigned int	y_tmp;
	float			yy;
	float			xx;
	float			invWidth;
	float			invHeight;
	float			fov;
	float			aspectratio;
	float			angle;
	int				state;
	unsigned int	zmax;
	t_vec			*raydir;
	t_vec			*rayorig;
	int				multi_threading;
}					t_render;



typedef struct		s_super
{
	t_trace		*trace;
	t_render	*render;
	t_spher		*sphere;
	t_win		*win;
	t_list		*list;


}					t_super;


t_list			*ft_lstnew_2(t_spher *content, size_t content_size);
t_list			*rt_parser_main(int argc, char **argv);
t_vec			*new_params_vec(float x, float y, float z);
t_pspher		*new_params_pspher(float radius, float refl, float opac);
t_spher			*new_params_spher(t_vec *pos, t_vec *color, t_pspher *ps);
t_vec			*new_sub_params_vec(t_vec *vec1, t_vec *vec2);
t_list			*ft_lstnew_2(t_spher *content, size_t content_size);
void			*sphere_to_void(t_spher *sphere);
void			img_add_px(t_win *mlx, unsigned int color, int x, int y);
void			normalize_vec(t_vec *vec);
void			push_params_vec(float x, float y, float z, t_vec *vec);
void			test_img(t_win *win);
void			ft_lstadd_2(t_list **last, t_list *elem);
double			ft_adolphe(char *str);
float			dot_product(t_vec *vec1, t_vec *vec2);
int				intersect(t_vec *rayorig, t_vec *raydir, float t0, float t1, t_spher *sphere);
t_vec			*trace(t_vec *rayorig, t_vec *raydir, int depth, t_list *list, t_trace *dat);

#endif
