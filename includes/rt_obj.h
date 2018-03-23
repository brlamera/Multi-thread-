/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:23:11 by juthomas          #+#    #+#             */
/*   Updated: 2017/12/04 16:45:15 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_H
# define RT_OBJ_H
typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_pbasic
{
	float			refl;
	float			opac;
}					t_pbasic;

typedef struct		s_plan
{
	struct s_vec	*pos;
	struct s_vec	*rot;
	struct s_vec	*color;
	struct s_pbasic	*pbasic;
}					t_plan;

typedef struct		s_pcycon
{
	float			radius;
	float			height;
	float			refl;
	float			opac;
}					t_pcycon;

typedef struct		s_cycon
{
	struct s_vec	*pos;
	struct s_vec	*rot;
	struct s_vec	*color;
	struct s_pcycon	*pc;
}					t_cycon;

typedef struct		s_pspher
{
	float			radius;
	float			refl;
	float			opac;
}					t_pspher;

typedef struct		s_spher
{
	struct s_vec	*pos;
	struct s_vec	*color;
	struct s_pspher	*pspher;
}					t_spher;

typedef struct		s_pdisque
{
	float			radius;
	float			refl;
	float			opac;
}					t_pdisque;

typedef struct		s_disque
{
	struct s_vec		*pos;
	struct s_vec		*rot;
	struct s_vec		*color;
	struct s_pdisque	*pdisque;
}					t_disque;

typedef struct		s_triangle
{
	struct s_vec	*p1;
	struct s_vec	*p2;
	struct s_vec	*p3;
	struct s_vec	*color;
	struct s_pbasic	*pbas;
}					t_triangle;

#endif
