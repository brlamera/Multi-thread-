/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:23:54 by juthomas          #+#    #+#             */
/*   Updated: 2017/11/07 07:36:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# define X_WIN 800
# define Y_WIN 500
# define INFINI 200
typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_pspher
{
	float			radius;
	float			refl;
	float			trans;
}					t_pspher;

typedef struct		s_spher
{
	struct s_vec	pos;
	float			radius;
	struct s_vec	color;
	float			refl;
	float			trans;
	struct s_vec	emi;
	struct s_pspher	ps;
}					t_spher;

typedef struct		s_win
{
	int				bpp;
	int				sizeline;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
}					t_win;

#endif
