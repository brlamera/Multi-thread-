/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:02:43 by juthomas          #+#    #+#             */
/*   Updated: 2018/02/06 00:38:38 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_LIGHT
# define RT_LIGHT

typedef struct			s_lplan
{
	struct s_vec		*pos;
	struct s_vec		*rot;
	struct s_vec		*color;
	float				emi;
}						t_lplan;

typedef struct			s_lpcycon
{
	float				radius;
	float				height;
	float				emi;
}						t_lpcyl;

typedef struct			s_lcycon
{
	struct s_vec		*pos;
	struct s_vec		*rot;
	struct s_vec		*color;
	struct s_lpcycon	*lpc;
}						t_lcycon;

typedef struct			s_lpspher
{
	float				radius;
	float				emi;
}						t_lpspher;

typedef struct			s_lspher
{
	struct s_vec		*pos;
	struct s_vec		*color;
	struct s_lpspher	*lpspher;
}						t_lspher;

typedef struct			s_lpdisque
{
	float				radius;
	float				emi;
}						t_lpdisque;

typedef struct			s_ldisque
{
	struct s_vec		*pos;
	struct s_vec		*rot;
	struct s_vec		*color;
	struct s_lpdisque	*lpdisque;
}						t_ldisque;


typedef struct			s_ltriangle
{
	struct s_vec		*p1;
	struct s_vec		*p2;
	struct s_vec		*p3;
	struct s_vec		*color;
	float				emi;
}						t_ltriangle;
#endif
