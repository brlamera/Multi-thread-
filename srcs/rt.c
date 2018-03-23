/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:22:04 by juthomas          #+#    #+#             */
/*   Updated: 2018/03/23 01:06:11 by brlamera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_obj.h"
#include "../includes/rt.h"
#include <pthread.h>

t_vec	*new_params_vec(float x, float y, float z)
{
	t_vec		*vec;

	vec = (t_vec*)malloc(sizeof(*vec));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

void	cpy_params_vec(t_vec *vec, t_vec *ret)
{
	ret->x = vec->x;
	ret->y = vec->y;
	ret->z = vec->z;
}

void	mult_vec_by_vec(t_vec *vec1, t_vec *vec2, t_vec *ret)
{
	ret->x = vec1->x * vec2->x;
	ret->y = vec1->y * vec2->y;
	ret->z = vec1->z * vec2->z;
}

void	mult_params_vec(t_vec *vec, float mult)
{
	vec->x *= mult;
	vec->y *= mult;
	vec->z *= mult;
}

t_pspher	*new_params_pspher(float radius, float refl, float opac)
{
	t_pspher	*ps;

	ps = (t_pspher*)malloc(sizeof(*ps));
	ps->radius = radius;
	ps->refl = refl;
	ps->opac = opac;
	return (ps);
}

t_spher		*new_params_spher(t_vec *pos, t_vec *color, t_pspher *ps)
{
	t_spher		*sphere;

	sphere = (t_spher*)malloc(sizeof(*sphere));
	sphere->pos = pos;
	sphere->color = color;
	sphere->pspher = ps;
	return (sphere);
}

void	sub_params_vec(t_vec *vec1, t_vec *vec2, t_vec *vec)
{
	vec->x = vec1->x - vec2->x;
	vec->y = vec1->y - vec2->y;
	vec->z = vec1->z - vec2->z;
}

t_vec	*new_sub_params_vec(t_vec *vec1, t_vec *vec2)
{
	t_vec *vec;

	vec = (t_vec*)malloc(sizeof(*vec));
	vec->x = vec1->x - vec2->x;
	vec->y = vec1->y - vec2->y;
	vec->z = vec1->z - vec2->z;
	return (vec);
}

void	push_color_vec(unsigned int color, t_vec *vec)
{
	vec->x = color / 0x10000  % 0x100;
	vec->y = color / 0x100 % 0x100;
	vec->z = color % 0x100;
}

unsigned int	vec_to_color(t_vec *vec)
{
	unsigned int	color;

	color = 0;
	if (vec->x < 1)
		color += (int)(vec->x * 0xff) * 0x10000;
	else
		color += 0xff * 0x10000;
	if (vec->y < 1)
		color += (int)(vec->y * 0xff) * 0x100;
	else
		color += 0xff * 0x100;
	if (vec->z < 1)
		color += vec->z * 0xff;
	else
		color += 0xff;
	return (color);
}


void	push_params_vec(float x, float y, float z, t_vec *vec)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void	push_one4all_param_vec(float x, t_vec *vec)
{
	vec->x = x;
	vec->y = x;
	vec->z = x;
}

unsigned int	img_get_px(t_win *mlx, int x, int y)
{
	unsigned int	color;

	color = 0;
	if (x < X_IMG && y < Y_IMG && x >= 0 && y >= 0)
	{
		color = mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)];
		color += mlx->addr[(y * mlx->sizeline + x *
			mlx->bpp / 8) + 1] * 256;
		color += mlx->addr[(y * mlx->sizeline + x *
			mlx->bpp / 8) + 2] * 256 * 256;
	}
	return (color);
}

void		img_add_px(t_win *mlx, unsigned int color, int x, int y)
{

//		printf("COOOLEOEOENF %x\n", color);
	if (x < X_IMG && y < Y_IMG && x >= 0 && y >= 0)
	{
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)] = color;
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] = color >> 8;
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] = color >> 16;
	}
}

void		img_add_px2(t_win *mlx, unsigned int color, int x, int y)
{

//		printf("COOOLEOEOENF %x\n", color);
	if (x < X_WIN && y < Y_WIN && x >= 0 && y >= 0)
	{
		mlx->addr2[(y * mlx->sizeline2 + x * mlx->bpp2 / 8)] = color;
		mlx->addr2[(y * mlx->sizeline2 + x * mlx->bpp2 / 8) + 1] = color >> 8;
		mlx->addr2[(y * mlx->sizeline2 + x * mlx->bpp2 / 8) + 2] = color >> 16;
	}
}


void		img_add_px3(t_win *mlx, unsigned int color, int x, int y)
{

//		printf("COOOLEOEOENF %x\n", color);
	if (x < X_WIN && y < Y_WIN && x >= 0 && y >= 0)
	{
		mlx->addr3[(y * mlx->sizeline3 + x * mlx->bpp3 / 8)] = color;
		mlx->addr3[(y * mlx->sizeline3 + x * mlx->bpp3 / 8) + 1] = color >> 8;
		mlx->addr3[(y * mlx->sizeline3 + x * mlx->bpp3 / 8) + 2] = color >> 16;
	}
}


void	normalize_vec(t_vec *vec)
{
	float	inv_len_vec;

	inv_len_vec = 1 / sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x *= inv_len_vec;
	vec->y *= inv_len_vec;
	vec->z *= inv_len_vec;
}

float	dot_product(t_vec *vec1, t_vec *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

int		intersect_spher(t_vec *rayorig, t_vec *raydir, float *t0, float *t1, t_spher *sphere)
{
	t_vec	*l;
	float	tca;
	float	d2;
	float	thc;

	l = new_sub_params_vec(sphere->pos, rayorig);
//	printf("x = %f, y = %f, z = %f", l.x, l.y, l.z);
//	printf("x = %f, y = %f, z = %f	", sphere->pos.x, sphere->pos.y, sphere->pos.z);
//	printf("x = %f, y = %f, z = %f\n", raydir->x, raydir->y, raydir->z);
	tca = dot_product(l, raydir);
//	printf("tca = %f", tca);
	if (tca < 0)
		return (0);
	d2 = dot_product(l, l) - tca * tca;
	if (d2 > sphere->pspher->radius * sphere->pspher->radius)
		return (0);
	thc = sqrt(sphere->pspher->radius * sphere->pspher->radius - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (1);
}

float			mixitude(float x, float y, float a)
{
	return (x * (1 - a) + y * a);
}

double			powered(double nb, int power)
{
	double	tmp;

	tmp = nb;
	if (power < 0)
	{
		if (nb == 0)
			return (INFINITY);
		while (power <= 0)
		{
			tmp /= nb;
			power++;
		}
	}
	else if (power == 0)
		return (1.0);
	else
	{
		while (power > 1)
		{
			tmp *= nb;
			power--;
		}
	}
	return (tmp);
}

void		rm_trace(t_trace *ret)
{


	free(ret->surface_color);
	free(ret->phit);
	free(ret->nhit);
	free(ret->refldir);
//	free(ret->reflection);
//	free(ret->refraction);
	free(ret->tmp_vec);
	free(ret->refrdir);
	free(ret->lum_inc);










}



t_trace		*setup_trace(void)
{
	t_trace		*ret;

	if ((ret = (t_trace*)malloc(sizeof(*ret))) == 0)
		exit(-1);
	ret->inter = 0;
	ret->spher = 0;
	ret->sphere = 0;


	ret->tnear = INFINI;
	ret->surface_color = new_params_vec(0, 0, 0);
	ret->phit = new_params_vec(0, 0, 0);
	ret->nhit = new_params_vec(0, 0, 0);


	ret->refldir = new_params_vec(0, 0, 0);
	ret->reflection = new_params_vec(0, 0, 0);
	ret->refraction = new_params_vec(0, 0, 0);

	ret->tmp_vec = new_params_vec(0, 0, 0);
	ret->refrdir = new_params_vec(0, 0, 0);
	ret->lum_inc = new_params_vec(0, 0, 0);

	ret->depth = 0;
	return (ret);
}

void		reset_trace(t_trace *trace)
{
	trace->inter = 0;
	trace->spher = 0;
	trace->sphere = 0;

	trace->tnear = INFINI;
	push_params_vec(0, 0, 0, trace->surface_color);
	push_params_vec(0, 0, 0, trace->phit);
	push_params_vec(0, 0, 0, trace->nhit);


	push_params_vec(0, 0, 0, trace->refldir);
	push_params_vec(0, 0, 0, trace->reflection);
	push_params_vec(0, 0, 0, trace->refraction);



}


void	apply_color(t_vec *surface_color, t_vec *color)
{
	float r;
	float g;
	float b;

	r = surface_color->x;
	g = surface_color->y;
	b = surface_color->z;

	surface_color->x = (1-r) * color->x + r;
	surface_color->y = (1-g) * color->y + g;
	surface_color->z = (1-b) * color->z + b;
//	printf("t########################### %f\n", r);

}

void	compute_color(t_trace *dat)
{

//		push_params_vec((dat->reflection->x * dat->fresneleffect + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) * (dat->sphere->color->x * 2),
//				(dat->reflection->y * dat->fresneleffect + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac)  * (dat->sphere->color->y * 2),
//				(dat->reflection->z * dat->fresneleffect + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) * (dat->sphere->color->z * 2),
//				dat->surface_color);
	float	refl; //(dat->sphere->pspher->refl)
	float	trans; //(dat->sphere->pspher->opac)
	float	col;
	float	refr[3];
	float	att;

	refl = dat->sphere->pspher->refl / (dat->sphere->pspher->refl + dat->sphere->pspher->opac + ((1 - dat->sphere->pspher->refl) * (1 - dat->sphere->pspher->opac)));
	trans = dat->sphere->pspher->opac / (dat->sphere->pspher->refl + dat->sphere->pspher->opac + ((1 - dat->sphere->pspher->refl) * (1 - dat->sphere->pspher->opac)));
	col = ((1 - dat->sphere->pspher->refl) * (1 - dat->sphere->pspher->opac)) / (dat->sphere->pspher->refl + dat->sphere->pspher->opac + ((1 - dat->sphere->pspher->refl) * (1 - dat->sphere->pspher->opac)));

//	dat->surface_color->x = dat->reflection->x * refl + dat->refraction->x * trans + dat->sphere->color->x * col * dat->reflection->x;
//	dat->surface_color->y = dat->reflection->y * refl + dat->refraction->y * trans + dat->sphere->color->y * col * dat->reflection->y;
//	dat->surface_color->z = dat->reflection->z * refl + dat->refraction->z * trans + dat->sphere->color->z * col * dat->reflection->z;

//	dat->surface_color->x = dat->reflection->x * refl * (dat->fresneleffect) + dat->refraction->x * trans * (1 - dat->fresneleffect) + dat->sphere->color->x * col * dat->reflection->x ;
//	dat->surface_color->y = dat->reflection->y * refl * (dat->fresneleffect) + dat->refraction->y * trans * (1 - dat->fresneleffect) + dat->sphere->color->y * col * dat->reflection->y;
//	dat->surface_color->z = dat->reflection->z * refl * (dat->fresneleffect) + dat->refraction->z * trans * (1 - dat->fresneleffect) + dat->sphere->color->z * col * dat->reflection->z;

//	dat->surface_color->x = dat->reflection->x * refl * (dat->fresneleffect) + dat->refraction->x * trans * (1 - dat->fresneleffect) + dat->sphere->color->x * col * dat->reflection->x * (1-dat->fresneleffect);
//	dat->surface_color->y = dat->reflection->y * refl * (dat->fresneleffect) + dat->refraction->y * trans * (1 - dat->fresneleffect) + dat->sphere->color->y * col * dat->reflection->y * (1-dat->fresneleffect);
//	dat->surface_color->z = dat->reflection->z * refl * (dat->fresneleffect) + dat->refraction->z * trans * (1 - dat->fresneleffect) + dat->sphere->color->z * col * dat->reflection->z * (1-dat->fresneleffect);

//	if (dat->lumiere_inc == 2)
//		dat->lumiere_inc = 1;
	att = -10 * log10(dat->sphere->pspher->opac);
	if (att > 1)
		att = 1;
	refr[0] = dat->refraction->x * (1 - att) + dat->sphere->color->x * dat->refraction->x * (att);
	refr[1] = dat->refraction->y * (1 - att) + dat->sphere->color->y * dat->refraction->y * (att);
	refr[2] = dat->refraction->z * (1 - att) + dat->sphere->color->z * dat->refraction->z * (att);

//	refr[0] = dat->refraction->x * (att) + dat->sphere->color->x * dat->refraction->x * (1-att);
//	refr[1] = dat->refraction->y * (att) + dat->sphere->color->y * dat->refraction->y * (1-att);
//	refr[2] = dat->refraction->z * (att) + dat->sphere->color->z * dat->refraction->z * (1-att);


if (0)
{
	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + dat->refraction->x * trans + dat->sphere->color->x * col * dat->reflection->x * (1-dat->fresneleffect);
	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + dat->refraction->y * trans + dat->sphere->color->y * col * dat->reflection->y * (1-dat->fresneleffect);
	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + dat->refraction->z * trans + dat->sphere->color->z * col * dat->reflection->z * (1-dat->fresneleffect);
}
else if (0)
{
	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + refr[0] * trans + dat->sphere->color->x * col * dat->reflection->x * (1-dat->fresneleffect);
	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + refr[1] * trans + dat->sphere->color->y * col * dat->reflection->y * (1-dat->fresneleffect);
	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + refr[2] * trans + dat->sphere->color->z * col * dat->reflection->z * (1-dat->fresneleffect);
}
else if (0)
{
	dat->surface_color->x = refr[0] * 1;//trans;
	dat->surface_color->y =  refr[1] * 1;//trans;
	dat->surface_color->z =  refr[2] * 1;//trans;
}



//	if (dat->lumiere_inc != 0 )
//	printf("printf(%f\n)", dat->lumiere_inc);
//	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + dat->refraction->x * trans + dat->sphere->color->x * col * dat->lumiere_inc * (1-dat->fresneleffect);
//	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + dat->refraction->y * trans + dat->sphere->color->y * col * dat->lumiere_inc * (1-dat->fresneleffect);
//	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + dat->refraction->z * trans + dat->sphere->color->z * col * dat->lumiere_inc * (1-dat->fresneleffect);


//	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + dat->refraction->x * trans + dat->sphere->color->x * col * dat->lum_inc->x * (1-dat->fresneleffect);
//	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + dat->refraction->y * trans + dat->sphere->color->y * col * dat->lum_inc->y * (1-dat->fresneleffect);
//	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + dat->refraction->z * trans + dat->sphere->color->z * col * dat->lum_inc->z * (1-dat->fresneleffect);


//	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + dat->refraction->x * trans * (1 - dat->fresneleffect) + dat->sphere->color->x * col * dat->reflection->x * (dat->fresneleffect);
//	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + dat->refraction->y * trans * (dat->fresneleffect) + dat->sphere->color->y * col * dat->reflection->y * (dat->fresneleffect);
//	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + dat->refraction->z * trans * ( dat->fresneleffect) + dat->sphere->color->z * col * dat->reflection->z * (dat->fresneleffect);
if (0)
{
	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + refr[0] * trans + dat->sphere->color->x * col * dat->lum_inc->x * (1-dat->fresneleffect);
	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + refr[1] * trans + dat->sphere->color->y * col * dat->lum_inc->y * (1-dat->fresneleffect);
	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + refr[2] * trans + dat->sphere->color->z * col * dat->lum_inc->z * (1-dat->fresneleffect);
}
else if (1)
{
	dat->surface_color->x = dat->reflection->x * refl * (1-dat->fresneleffect) + refr[0] * trans * (1-dat->fresneleffect) + dat->sphere->color->x * col * dat->lum_inc->x * (1-dat->fresneleffect);
	dat->surface_color->y = dat->reflection->y * refl * (1-dat->fresneleffect) + refr[1] * trans * (1-dat->fresneleffect) + dat->sphere->color->y * col * dat->lum_inc->y * (1-dat->fresneleffect);
	dat->surface_color->z = dat->reflection->z * refl * (1-dat->fresneleffect) + refr[2] * trans * (1-dat->fresneleffect) + dat->sphere->color->z * col * dat->lum_inc->z * (1-dat->fresneleffect);
}









	//	return (dat->surface_color)
}


void	compute_light(t_trace *dat, t_list *cpy_lst)
{
	t_list *list;
	t_list *tmp_lst;
	float color;
	float colortt;
	list = cpy_lst;
	colortt = 0;
	t_vec *tmp_vec;
	float useless1;
	float useless2;
	t_vec *tmp_color;
	float att;
	float refr[3];
	tmp_color = new_params_vec(0,0,0);
	tmp_vec = new_params_vec(0,0,0);
	while(list)
	{



		dat->type = list->content;
		if (dat->type->name == 'S')
		{
		//	spher = type->obj;
			dat->lsphere = dat->type->obj;
///			if (intersect_spher(rayorig, raydir, &t0, &t1, spher))
			color = 1;
			cpy_params_vec(dat->lsphere->color, dat->lum_inc);
			mult_params_vec(dat->lum_inc, dat->lsphere->lpspher->emi);

				tmp_lst = cpy_lst;
				while(tmp_lst)
				{
//					type = list->content;
					dat->type = tmp_lst->content;
///		if (type->name == 's')
					if (dat->type->name == 's')
					{
//						spher = type->obj;
						dat->spher = dat->type->obj;
///						if (intersect_spher(rayorig, raydir, &t0, &t1, spher))
						sub_params_vec(dat->lsphere->pos, dat->phit, tmp_vec);
						normalize_vec(tmp_vec);
						if (intersect_spher(dat->phit, tmp_vec, &useless1, &useless2, dat->spher))
						{

//							color = 1;
						//	mult_vec_by_vec(dat->lum_inc, dat->spher->color, dat->lum_inc);
							att = -10 * log10(dat->spher->pspher->opac);
							if (att > 1)
								att = 1;
							dat->lum_inc->x = dat->lum_inc->x * (1 - att) + dat->lum_inc->x * dat->spher->color->x * (att);
							dat->lum_inc->y = dat->lum_inc->y * (1 - att) + dat->lum_inc->y * dat->spher->color->y * (att);
							dat->lum_inc->z = dat->lum_inc->z * (1 - att) + dat->lum_inc->z * dat->spher->color->z * (att);

							mult_params_vec(dat->lum_inc, dat->spher->pspher->opac / (dat->spher->pspher->refl + dat->spher->pspher->opac + ((1 - dat->spher->pspher->refl) * (1 - dat->spher->pspher->opac))));
;
							color *= (dat->spher->pspher->opac);
						}
					}
					tmp_lst = tmp_lst->next;
				}
			colortt += color;
		}
		list = list->next;
	}
	dat->lumiere_inc = colortt;
}

t_vec	*trace(t_vec *rayorig, t_vec *raydir,  int depth, t_list *list, t_trace *dat)
{
//	int		inter;
///	t_spher	*spher;
//	t_spher *sphere;
//	t_type	*type;
//	float	t0;
//	float	t1;
//	t_vec	*surface_color;
//	t_vec	*phit;
//	t_vec	*nhit;
//	float	tnear;
//	short	inside;
//	float	bias;
//	float	facingratio;
//	float	fresneleffect;
//	t_vec	*refldir;
//	t_vec	*reflection;
//	t_vec	*refraction;
	t_list	*cpy_lst;
//	t_list	*tmp_lst;



	reset_trace(dat);
//	tnear = INFINI;
//	inter = 0;
//	if (intersect(rayorig, raydir, INFINI, INFINI, sphere))
//		return (0x000000);
//	if (intersect(rayorig, raydir, INFINI, INFINI, sphere))
//		return (0x000000);


	dat->lumiere_inc = 0;
//	sphere = 0;
	push_params_vec(0, 0, 0, dat->tmp_vec);
	cpy_lst = list;
//	ft_putstr("WW");
	while (list)
	{
//		t0 = INFINI;
		dat->t0 = INFINI;
//		t1 = INFINI;
		dat->t1 = INFINI;
//		type = list->content;
		dat->type = list->content;
///		if (type->name == 's')
		if (dat->type->name == 's')
		{
	//		spher = type->obj;
			dat->spher = dat->type->obj;
///			if (intersect_spher(rayorig, raydir, &t0, &t1, spher))
			if (intersect_spher(rayorig, raydir, &dat->t0, &dat->t1, dat->spher))
			{
				//inter = 1;
				if (dat->t0 < 0)
					dat->t0 = dat->t1;
				if (dat->t0 < dat->tnear)
				{
					dat->inter = 1;
				//tnear = t0;
				dat->tnear = dat->t0;
				//sphere = spher;
				dat->sphere = dat->spher;
				//		printf("££££££££ t0 = %f\n", t0);
		//		printf("££££££££ t1 = %f\n", t1);
				}
			}
		}
		list = list->next;
	}

//	ft_putstr("..");
///	if (!sphere)
///		return (0xffffff);
	if (!dat->sphere)
		return (new_params_vec(1, 1, 1));

//	ft_putstr("OO");
//	surface_color	= new_params_vec(0, 0, 0);

//	phit = new_params_vec(rayorig->x + raydir->x * tnear, rayorig->y + raydir->y * tnear, rayorig->z + raydir->z * tnear);
	push_params_vec(rayorig->x + raydir->x * dat->tnear, rayorig->y + raydir->y * dat->tnear, rayorig->z + raydir->z * dat->tnear, dat->phit);

//	nhit = new_params_vec(phit->x - sphere->pos->x, phit->y - sphere->pos->y, phit->z - sphere->pos->z);
	push_params_vec(dat->phit->x - dat->sphere->pos->x, dat->phit->y - dat->sphere->pos->y, dat->phit->z - dat->sphere->pos->z, dat->nhit);
	// UTILISER PUSH PARAM AU LIEU DE NEW PARAM;
	normalize_vec(dat->nhit);
//	bias = 0.0001;
	dat->bias = 0.0001;

//	ft_putstr("WERWERW");
//	inside = 0;
	dat->inside = 0;

	//if (dot_product(raydir, nhit) > 0)
	if (dot_product(raydir, dat->nhit) > 0)
	{
	//	nhit = -nhit;
//		push_params_vec(-nhit->x, -nhit->y, -nhit->z, nhit);
		push_params_vec(-dat->nhit->x, -dat->nhit->y, -dat->nhit->z, dat->nhit);

//		inside = 1;
		dat->inside = 1;
	}
	if (dat->sphere->pspher->radius == 4 && dat->test == 1)
	{
		printf("OPACITYYYYY : %f\n", dat->sphere->pspher->opac);
		dat->test = 0;
	}

//	if ((sphere->pspher->opac > 0 || sphere->pspher->refl > 0) && depth < MAX_RAY_DEPTH)
	if ((dat->sphere->pspher->opac > 0 || dat->sphere->pspher->refl > 0) && dat->depth < MAX_RAY_DEPTH)
	{
//		facingratio = -dot_product(raydir, nhit);
		dat->facingratio = -dot_product(raydir, dat->nhit);

//		fresneleffect = mixitude(powered(1 - facingratio, 3), 1, 0.1);
		dat->fresneleffect = mixitude(powered(1 - dat->facingratio, 3), 1, 0.1);

		push_params_vec(raydir->x - dat->nhit->x * 2 * dot_product(raydir, dat->nhit),
						raydir->y - dat->nhit->y * 2 * dot_product(raydir, dat->nhit),
						raydir->z - dat->nhit->z * 2 * dot_product(raydir, dat->nhit), dat->refldir);

		normalize_vec(dat->refldir);

		t_trace *new_trace;

		new_trace	 = setup_trace();
		new_trace->depth = dat->depth + 1;
		push_params_vec(dat->phit->x + dat->nhit->x * dat->bias,
				dat->phit->y + dat->nhit->y * dat->bias,
				dat->phit->z + dat->nhit->z * dat->bias, dat->tmp_vec);

	//	printf("helloworld\n");


		dat->reflection = trace(dat->tmp_vec, dat->refldir, depth, cpy_lst, new_trace);

	//	dat->reflection = new_params_vec(123, 123, 231);
//		rm_trace(new_trace);

//		t_vec *reffffff;
//		reffffff = trace(dat->tmp_vec, dat->refldir, depth, cpy_lst, dat);

			push_params_vec(0, 0, 0, dat->refraction);

	//		printf("OOPPPPPPPACC SPPPHEEERRR  === %f\n", dat->sphere->pspher->opac);
		if (dat->sphere->pspher->opac)
		{
			dat->ior = 1.1;
			if (dat->inside == 1)
				dat->eta = dat->ior;
			else
				dat->eta = 1 / dat->ior;
			dat->cosi = -dot_product(dat->nhit, raydir);
			dat->k = 1 - dat->eta * dat->eta * (1 - dat->cosi - 4.);  ///////////////////////////////////////////////////////////////// BUG WAS HERE

// ou			dat->k = 1 - dat->eta * dat->eta * (1 - dat->cosi * dat->cosi);  ///////////////////////////////////////////////////////////////// BUG WAS HERE

			push_params_vec(raydir->x * dat->eta + dat->nhit->x * (dat->eta * dat->cosi - sqrt(dat->k)),
					raydir->y * dat->eta + dat->nhit->y * (dat->eta * dat->cosi - sqrt(dat->k)),
					raydir->z * dat->eta + dat->nhit->z * (dat->eta * dat->cosi - sqrt(dat->k)), dat->refrdir);
			normalize_vec(dat->refrdir);


		t_trace *new_trace2;

		new_trace2	 = setup_trace();
			new_trace2->depth = dat->depth + 1;

			push_params_vec(dat->phit->x - dat->nhit->x * dat->bias,
				dat->phit->y - dat->nhit->y * dat->bias,
				dat->phit->z - dat->nhit->z * dat->bias, dat->tmp_vec);

				dat->refraction = trace(dat->tmp_vec, dat->refrdir, depth, cpy_lst, new_trace2);

		}

	//	push_params_vec((dat->reflection->x * dat->fresneleffect + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) ,
	//			(dat->reflection->y * dat->fresneleffect + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) ,
	//			(dat->reflection->z * dat->fresneleffect + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) ,
	//			dat->surface_color);

	//	apply_color(dat->surface_color, dat->sphere->color);

		//true
//		push_params_vec((dat->reflection->x * dat->fresneleffect * dat->sphere->color->x + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) ,
//				(dat->reflection->y * dat->fresneleffect * dat->sphere->color->y + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) ,
//				(dat->reflection->z * dat->fresneleffect  * dat->sphere->color->z + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac),
//				dat->surface_color);


	//	cpy_lst = list;






	compute_light(dat, cpy_lst);







		compute_color(dat);

//		push_params_vec((dat->reflection->x * dat->fresneleffect + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) * (dat->sphere->color->x * 2),
//				(dat->reflection->y * dat->fresneleffect + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac)  * (dat->sphere->color->y * 2),
//				(dat->reflection->z * dat->fresneleffect + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac) * (dat->sphere->color->z * 2),
//				dat->surface_color);

	//	push_params_vec((dat->reflection->x * dat->fresneleffect + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac),
	//			(dat->reflection->y * dat->fresneleffect + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac)  ,
	//			(dat->reflection->z * dat->fresneleffect + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac),
		//		dat->surface_color);

//		push_params_vec((dat->reflection->x * dat->fresneleffect + dat->refraction->x * (1 - dat->fresneleffect) * dat->sphere->pspher->opac +  (1.1 - dat->sphere->pspher->opac) * dat->sphere->color->x ) ,
//				(dat->reflection->y * dat->fresneleffect + dat->refraction->y * (1 - dat->fresneleffect) * dat->sphere->pspher->opac + (1.1 - dat->sphere->pspher->opac) * dat->sphere->color->y     ) ,
//				(dat->reflection->z * dat->fresneleffect + dat->refraction->z * (1 - dat->fresneleffect) * dat->sphere->pspher->opac   + (1.1 - dat->sphere->pspher->opac) * dat->sphere->color->z           ),
//				dat->surface_color);


	}
	else
	{
		push_params_vec(0.2, 0.44, 0.1, dat->surface_color);


	}

	//	if (inter)
//		return (0xFF0000);
	push_params_vec(dat->surface_color->x + dat->sphere->color->x,
			dat->surface_color->y + dat->sphere->color->y,
			dat->surface_color->z + dat->sphere->color->z, dat->tmp_vec);
	return (dat->surface_color);
	return (dat->tmp_vec);
	return (new_params_vec(0, 1, 1));
}

void	test_list(t_list *list)
{
	t_spher *sphere;
	int		i;
	t_type	*type;
	t_lspher *lsphere;

	sphere = (t_spher*)list->content;
	i = 0;
	while (list)
	{
		sphere = 0;
		lsphere = 0;
		if (list->content)
			type = list->content;
		if (type->name == 's')
			sphere = type->obj;
		else if (type->name == 'S')
			lsphere = type->obj;
		if (sphere)
		{
				printf("pos:  x= %f, y = %f, z = %f\n", sphere->pos->x, sphere->pos->y, sphere->pos->z);
				printf("color:  r= %f, g = %f, b = %f\n", sphere->color->x, sphere->color->y, sphere->color->z);
				printf("radius = %f, refl = %f, opac = %f\n", sphere->pspher->radius, sphere->pspher->refl, sphere->pspher->opac);
		}
		else if (lsphere)
		{
				printf("pos:  x= %f, y = %f, z = %f\n", lsphere->pos->x, lsphere->pos->y, lsphere->pos->z);
				printf("color:  r= %f, g = %f, b = %f\n", lsphere->color->x, lsphere->color->y, lsphere->color->z);
				printf("radius = %f, EMI = %f\n", lsphere->lpspher->radius, lsphere->lpspher->emi);
		}





		list = list->next;
	}
}

void	test_sphere(t_spher *sphere)
{
//	t_spher *sphere;
	int		i;
//	sphere = list->content;
	i = 0;
	while (i < 10000)
	{
	//	printf("x = %f, y = %f, z = %f\n", sphere->pos.x, sphere->pos.y, sphere->pos.z);
		i++;
	}
}

void	test_void(void *vo)
{
	t_spher *sphere;
	int		i;
	sphere = vo;
	i = 0;
	while (i < 10000)
	{
//		printf("x = %f, y = %f, z = %f\n", sphere->ps->radius, sphere->ps->refl, sphere->ps->trans);
		i++;
	}
}
void	*sphere_to_void(t_spher *sphere)
{
	void	*ret;
//	ret = (void*)malloc(sizeof(void*));
	ret = sphere;

	test_void(ret);
	return (ret);
}

void	test_img(t_win *win)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < X_WIN)
	{
		while (y < Y_WIN)
		{
			img_add_px2(win, 0xff00ff, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

t_list	*ft_lstnew_2(t_spher *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		new->content = content;
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstadd_2(t_list **last, t_list *elem)
{
	t_list	*old;

	old = *last;
	*last = elem;
	elem->next = old;
}




void	render(t_spher *sphere, t_win *win, t_list *list)
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	y;
	unsigned int	x;
	float			yy;
	float			xx;
	float			invWidth;
	float			invHeight;
	float			fov;
	float			aspectratio;
	float			angle;
	t_vec			*raydir;
	t_vec			*rayorig;
	t_trace			*datrace;

	raydir = new_params_vec(0, 0, 0);
	rayorig = new_params_vec(0, 0, 0);
	width = X_IMG;
	height = Y_IMG;
	invWidth = 1.0 / (float)width;
	invHeight = 1.0 / (float)height;
	fov = 30;
	aspectratio = (float)width / (float)height;
	angle = tan(M_PI * 0.5 * fov / 180.);
	y = 0;

	datrace = setup_trace();
	while (y < height)
	{
		if (y == 55 && 0)
		{
			test_img(win);
			mlx_put_image_to_window(win->mlx, win->win,	win->img2, 0, 0);

	mlx_loop(win->mlx);
		}
		x = 0;
		while (x < width)
		{
			xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio;
			yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
			push_params_vec(xx, yy, -1, raydir);
			reset_trace(datrace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(win, vec_to_color(trace(rayorig, raydir, 0, list, datrace)), x, y);
			x++;
		}
		y++;
	}
}





void	apply_autoauto(t_win *mlx)
{
	int				x;
	int				y;
//	unsigned int	r;
//	unsigned int	g;
//	unsigned int	b;
	unsigned int	color;
	int				x2;
	int				y2;

	x = 0;
	y = 0;
//	r = 0;
//	g = 0;
//	b = 0;
	x2 = 0;
	y2 = 0;
	color = 0;
	while (y2 < Y_WIN)
	{
		while (x2 < X_WIN)
		{
	//		r  = img_get_px(mlx, x)
		color = 0;
		x = x2 / 2 * 4 + x2 % 2;

		y = y2 / 2 * 4 + y2 % 2;
		color = (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)];



	//	color =0xff;

		color += (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] * 256;

		color += (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] * 256 * 256;
//	color = img_get_px(mlx, x, y);
		img_add_px3(mlx, color, x2, y2);
	//	printf("COOOLEOEOENF %x\n", color);

			x2++;
		}
		x2 = 0;
		y2++;
	}


}

void	apply_autofill(t_win *mlx)
{
	int				x;
	int				y;
//	unsigned int	r;
//	unsigned int	g;
//	unsigned int	b;
	unsigned int	color;
	int				x2;
	int				y2;

	x = 0;
	y = 0;
//	r = 0;
//	g = 0;
//	b = 0;
	x2 = 0;
	y2 = 0;
	color = 0;
	while (y2 < Y_WIN)
	{
		while (x2 < X_WIN)
		{
	//		r  = img_get_px(mlx, x)
		color = 0;
		x = x2 / 2 * 4;

		y = y2 / 2 * 4;
		color = (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)];



	//	color =0xff;

		color += (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] * 256;

		color += (unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] * 256 * 256;
//	color = img_get_px(mlx, x, y);
		img_add_px3(mlx, color, x2, y2);
	//	printf("COOOLEOEOENF %x\n", color);

			x2++;
		}
		x2 = 0;
		y2++;
	}


}

void	apply_antiaaaliasing(t_win *mlx)
{
	int				x;
	int				y;
//	unsigned int	r;
//	unsigned int	g;
//	unsigned int	b;
	unsigned int	color;
	int				x2;
	int				y2;

	x = 0;
	y = 0;
//	r = 0;
//	g = 0;
//	b = 0;
	x2 = 0;
	y2 = 0;
	color = 0;
	while (y2 < Y_WIN)
	{
		while (x2 < X_WIN)
		{
	//		r  = img_get_px(mlx, x)
		color = 0;
		x = x2 * 2;

		y = y2 * 2;
		color = ((unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)]
				+ (unsigned char)mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8)]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8)]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8)]) / 4;


	//	color =0xff;

		color += ((unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1]
				+ (unsigned char)mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 1]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 1]) / 4 * 256;


		color += ((unsigned char)mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2]
				+ (unsigned char)mlx->addr[(y * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + x * mlx->bpp / 8) + 2]
				+ (unsigned char)mlx->addr[((y + 1) * mlx->sizeline + (x + 1) * mlx->bpp / 8) + 2]) / 4 * 256 * 256;
//	color = img_get_px(mlx, x, y);
		img_add_px(mlx, color, x2, y2);
	//	printf("COOOLEOEOENF %x\n", color);

			x2++;
		}
		x2 = 0;
		y2++;
	}


}


void	test_color()
{
	printf("COLOR = ");







}

int	rt_close(void)
{
		exit(0);
		return (0);
}


int			key_hook(int keycode)
{
	if (keycode == 53 || keycode == 17)
		exit(0);
	return (0);
}

t_super		*setup_super(void)
{
	t_super *super;

	if ((super = (t_super*)malloc(sizeof(*super))) == NULL)
		exit(0);
	if ((super->trace = (t_trace*)malloc(sizeof(*super->trace))) == NULL)
		exit(0);
	if ((super->render = (t_render*)malloc(sizeof(*super->render))) == NULL)
		exit(0);
	if ((super->win = (t_win*)malloc(sizeof(*super->win))) == NULL)
		exit(0);


	super->render->raydir = new_params_vec(0, 0, 0);
	super->render->rayorig = new_params_vec(0, 0, 0);
	super->render->state = 1;



	return (super);
}

void	print_percent2(t_win *win, float percent)
{
	int		conv_int;

	conv_int = percent * 1000;
//	if (conv_int / 100 == 0)
//		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "0");
	if (conv_int / 100 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "1");
	else if (conv_int / 100 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "2");
	else if (conv_int / 100 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "3");
	else if (conv_int / 100 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "4");
	else if (conv_int / 100 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "5");
	else if (conv_int / 100 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "6");
	else if (conv_int / 100 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "7");
	else if (conv_int / 100 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "8");
	else if (conv_int / 100 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "9");
	else if (conv_int / 100 == 10)
	{
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, 0, 0xffffff, "0");
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 30, 0, 0xffffff, "1");
	}

	if (conv_int / 10 % 10 == 0)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "0");
	else if (conv_int / 10 % 10 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "1");
	else if (conv_int / 10 % 10 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "2");
	else if (conv_int / 10 % 10 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "3");
	else if (conv_int / 10 % 10 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "4");
	else if (conv_int / 10 % 10 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "5");
	else if (conv_int / 10 % 10 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "6");
	else if (conv_int / 10 % 10 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "7");
	else if (conv_int / 10 % 10 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "8");
	else if (conv_int / 10 % 10 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, 0, 0xffffff, "9");




	mlx_string_put(win->mlx, win->win, X_WIN / 2 , 0, 0xffffff, ".");
	if (conv_int % 10 == 0)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "0");
	else if (conv_int % 10 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "1");
	else if (conv_int % 10 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "2");
	else if (conv_int % 10 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "3");
	else if (conv_int % 10 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "4");
	else if (conv_int % 10 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "5");
	else if (conv_int % 10 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "6");
	else if (conv_int % 10 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "7");
	else if (conv_int % 10 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "8");
	else if (conv_int % 10 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , 0, 0xffffff, "9");
mlx_string_put(win->mlx, win->win, X_WIN / 2 + 20 ,  0, 0xffffff, "%");

}



void	print_percent(t_win *win, float percent)
{
	int		conv_int;

	conv_int = percent * 1000;
//	if (conv_int / 100 == 0)
//		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "0");
	if (conv_int / 100 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "1");
	else if (conv_int / 100 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "2");
	else if (conv_int / 100 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "3");
	else if (conv_int / 100 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "4");
	else if (conv_int / 100 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "5");
	else if (conv_int / 100 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "6");
	else if (conv_int / 100 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "7");
	else if (conv_int / 100 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "8");
	else if (conv_int / 100 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "9");
	else if (conv_int / 100 == 10)
	{
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 20, Y_WIN / 2 - 40, 0xffffff, "0");
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 30, Y_WIN / 2 - 40, 0xffffff, "1");
	}

	if (conv_int / 10 % 10 == 0)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "0");
	else if (conv_int / 10 % 10 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "1");
	else if (conv_int / 10 % 10 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "2");
	else if (conv_int / 10 % 10 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "3");
	else if (conv_int / 10 % 10 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "4");
	else if (conv_int / 10 % 10 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "5");
	else if (conv_int / 10 % 10 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "6");
	else if (conv_int / 10 % 10 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "7");
	else if (conv_int / 10 % 10 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "8");
	else if (conv_int / 10 % 10 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 - 10, Y_WIN / 2 - 40, 0xffffff, "9");




	mlx_string_put(win->mlx, win->win, X_WIN / 2 , Y_WIN / 2 - 40, 0xffffff, ".");
	if (conv_int % 10 == 0)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "0");
	else if (conv_int % 10 == 1)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "1");
	else if (conv_int % 10 == 2)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "2");
	else if (conv_int % 10 == 3)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "3");
	else if (conv_int % 10 == 4)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "4");
	else if (conv_int % 10 == 5)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "5");
	else if (conv_int % 10 == 6)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "6");
	else if (conv_int % 10 == 7)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "7");
	else if (conv_int % 10 == 8)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "8");
	else if (conv_int % 10 == 9)
		mlx_string_put(win->mlx, win->win, X_WIN / 2 + 10 , Y_WIN / 2 - 40, 0xffffff, "9");
mlx_string_put(win->mlx, win->win, X_WIN / 2 + 20 , Y_WIN / 2 - 40, 0xffffff, "%");

}

int		loading_screen2(t_win *win, float percent)
{
	int		x;
	int		y;

	x = 0;
	x = 0;
	y = 0;
	while (x < (X_WIN)/ 2)
	{
		while (y < 25)
		{
			if ((x <= percent * X_WIN / 2))
				img_add_px2(win, 0x00ff00, x, y);
			else if ((x <= X_WIN / 2))
				img_add_px2(win, 0x008000, x, y);
			else
				img_add_px2(win, 0x000000, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img2, X_WIN / 4, 0);

//	mlx_put_image_to_window(win->mlx, win->win, win->img3, 0, 0);
	print_percent2(win, percent);
	return (0);
}


int		loading_screen(t_win *win, float percent)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < X_WIN)
	{
		while (y < Y_WIN)
		{
			if ((y >= Y_WIN / 2 - 10 && y <= Y_WIN / 2 + 10) && (x >= X_WIN / 4 && x <= X_WIN / 4 + percent * X_WIN / 2))
				img_add_px2(win, 0x00ff00, x, y);
			else if ((y >= Y_WIN / 2 - 10 && y <= Y_WIN / 2 + 10) && (x >= X_WIN / 4 && x <= X_WIN / 4 + X_WIN / 2))
				img_add_px2(win, 0x008000, x, y);
			else
				img_add_px2(win, 0x000000, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img2, 0, 0);
	print_percent(win, percent);
	return (0);
}

void	r_render_setup(t_super *super)
{
	t_render		*r;

	r = super->render;

//	raydir = new_params_vec(0, 0, 0);
//	rayorig = new_params_vec(0, 0, 0);
	r->width = X_IMG;
	r->height = Y_IMG;
	r->invWidth = 1.0 / (float)r->width;
	r->invHeight = 1.0 / (float)r->height;
	r->fov = 30;
	r->aspectratio = (float)r->width / (float)r->height;
	r->angle = tan(M_PI * 0.5 * r->fov / 180.);
	r->y = 0;
	r->x = 0;
	r->z = 0;
	r->x_tmp = 0;
	r->y_tmp = 0;
	r->zmax = (X_IMG) * (Y_IMG);
	super->trace = setup_trace();
	super->render->state = 2;
}

void	r_render_tour_compute(t_super *super, unsigned int x, unsigned int y)
{
	t_render	*r;

	r = super->render;

			r->x = x;
			r->y = y;
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
			r->z++;
}

void	*r_render_tour_compute_m(void *t_pouse)
{
	t_super *super;
	t_render	*r;
	unsigned int y;
	unsigned int x;

	super = t_pouse;
	printf("maybe here?\n");
	r = super->render;
	x = (r->x_tmp) * 4;
	y = r->y_tmp * 4;
	printf("x = %d\ny = %d\nmulti = %d\n", x, y, r->multi_threading);

			r->x = x;
			r->y = y;
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
			// r->z++;
			pthread_exit(NULL);
}

void	*r_render_tour_compute_m2(void *t_pouse)
{
	t_super *super;
	t_render	*r;
	unsigned int y;
	unsigned int x;

	super = t_pouse;
	printf("maybe here?\n");
	r = super->render;
	x = (r->x_tmp + 1) * 4;
	y = r->y_tmp * 4;
	printf("x = %d\ny = %d\n", x, y);

			r->x = x;
			r->y = y;
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
			// r->z++;
			pthread_exit(NULL);
}

void	r_render_tour_phase_1(t_super *super)
{
	t_render		*r;
	pthread_t test1;
	pthread_t test2;
	// pthread_t test3;
	// pthread_t test4;


	printf("WTF\n");
	r = super->render;
	while (r->y_tmp <= r->height / 4)
	{
		printf("ici\n");
		while (r->x_tmp <= r->width / 4)
		{
		//	r->x = r->x_tmp * 4;
		//	r->y = r->y_tmp * 4;
		//	r_render_tour_compute(super, r->x_tmp * 4, r->y_tmp * 4);
	/*
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);
		*/
		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

		//	img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
		//	r->z++;

		//	r->x_tmp++;
		printf("la\n");
			if (r->x_tmp <= r->width / 4)
			{
				printf("thr1 ok?\n");
				pthread_create(&test1, NULL, r_render_tour_compute_m, super);
				printf("thr1 ok.\n");
			 }
			if (r->x_tmp + 1 <= r->width / 4)
			{
				printf("thr2 ok?\n");
				pthread_create(&test2, NULL, r_render_tour_compute_m2, super);
				printf("thr2 ok.\n");
			}
			// if (r->x_tmp + 2 <= r->width / 4)
			// {
			// 	printf("thr3 ok?\n");
			// 	r->multi_threading = 2;
			// 	pthread_create(&test3, NULL, r_render_tour_compute_m, super);
			// 	printf("thr3 ok.\n");
			// }
			// if (r->x_tmp + 3 <= r->width / 4)
			// {
			// 	printf("thr4 ok?\n");
			// 	r->multi_threading = 3;
			// 	pthread_create(&test4, NULL, r_render_tour_compute_m, super);
			// 	printf("thr4 ok.\n");
			// }
			ft_putstr("join?\n");
			if (r->x_tmp <= r->width / 4)
				pthread_join(test1, NULL);
			if (r->x_tmp + 1 <= r->width / 4)
				pthread_join(test2, NULL);
			// if (r->x_tmp + 2 <= r->width / 4)
			// 	pthread_join(test3, NULL);
			// if (r->x_tmp + 3 <= r->width / 4)
			// 	pthread_join(test4, NULL);
			ft_putstr("join effectue\n");
			// usleep(10000);
			r->z += 1;
			r->x_tmp += 2;
			 if ((r->z) % ((r->zmax / 1000) == 0 ? 1 : (r->zmax / 1000))  == 0)
		 	{
		 		(loading_screen2(super->win, (float)r->z / (float)r->zmax));
		 		return ;
		 	}



		}
		r->y_tmp++;
		r->x_tmp = 0;
	}

	apply_autofill(super->win);
	mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img3, 0, 0);
	super->render->state = 3;
}

void	r_render_tour_phase_2(t_super *super)
{
	t_render		*r;

	r = super->render;
	while (r->y_tmp <= r->height / 4)
	{

		while (r->x_tmp <= r->width / 4)
		{
			if (r->x_tmp <= (r->width - 1) / 4 )
				r_render_tour_compute(super, r->x_tmp * 4 + 1, r->y_tmp * 4);
			if (r->y_tmp <= (r->height - 1) / 4 )
				r_render_tour_compute(super, r->x_tmp * 4, r->y_tmp * 4 + 1);
			if (r->y_tmp <= (r->height - 1) / 4 && r->x_tmp <= (r->width - 1) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 1, r->y_tmp * 4 + 1);
			//if ((r->z) % ((r->zmax / 4000) == 0 ? 1 : (r->zmax / 4000))  == 0)

			if ((r->z) % 113 == 1)
			{

				(loading_screen2(super->win, (float)r->z / (float)r->zmax));
				return ;
			}

			r->x_tmp++;
		}
		r->y_tmp++;
		r->x_tmp = 0;
	}

	apply_autoauto(super->win);
	mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img3, 0, 0);
	super->render->state = 5;
}



void	r_render_tour_phase_3(t_super *super)
{
	t_render		*r;

	r = super->render;
//	printf("coucou");
//	ft_putstr("coucou");

	while (r->y_tmp <= r->height / 4)
	{

		while (r->x_tmp <= r->width / 4)
		{

//	ft_putstr("coucou");
			if (r->x_tmp <= (r->width - 2) / 4 )
				r_render_tour_compute(super, r->x_tmp * 4 + 2, r->y_tmp * 4);
			if (r->y_tmp <= (r->width - 3) / 4 )
				r_render_tour_compute(super, r->x_tmp * 4 + 3, r->y_tmp * 4);


			if (r->x_tmp <= (r->width - 2) / 4 && r->y_tmp <= (r->height - 1) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 2, r->y_tmp * 4 + 1);
			if (r->x_tmp <= (r->width - 3) / 4 && r->y_tmp <= (r->height - 1) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 3, r->y_tmp * 4 + 1);


			if (r->x_tmp <= (r->width) / 4 && r->y_tmp <= (r->height - 2) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 , r->y_tmp * 4 + 2);
			if (r->x_tmp <= (r->width - 1) / 4 && r->y_tmp <= (r->height - 2) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 1, r->y_tmp * 4 + 2);
			if (r->x_tmp <= (r->width - 2) / 4 && r->y_tmp <= (r->height - 2) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 2, r->y_tmp * 4 + 2);
			if (r->x_tmp <= (r->width - 3) / 4 && r->y_tmp <= (r->height - 2) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 3, r->y_tmp * 4 + 2);

			if (r->x_tmp <= (r->width) / 4 && r->y_tmp <= (r->height - 3) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 , r->y_tmp * 4 + 3);
			if (r->x_tmp <= (r->width - 1) / 4 && r->y_tmp <= (r->height - 3) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 1, r->y_tmp * 4 + 3);
			if (r->x_tmp <= (r->width - 2) / 4 && r->y_tmp <= (r->height - 3) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 2, r->y_tmp * 4 + 3);
			if (r->x_tmp <= (r->width - 3) / 4 && r->y_tmp <= (r->height - 3) / 4)
				r_render_tour_compute(super, r->x_tmp * 4 + 3, r->y_tmp * 4 + 3);







			if (r->z % 113 == 1)
			{

	//			ft_putstr("coucou");
				(loading_screen2(super->win, (float)r->z / (float)r->zmax));
				return ;
			}
//
			r->x_tmp++;
		}
		r->y_tmp++;
		r->x_tmp = 0;
	}

	ft_putstr("coucou");
	apply_antiaaaliasing(super->win);
	mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img, 0, 0);
	super->render->state = 7;
}





void	r_render_tour(t_super *super)
{
	t_render		*r;

	r = super->render;
	while (r->y < r->height)
	{
		if (r->y == 55 && 0)
		{
			test_img(super->win);
			mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img2, 0, 0);

	mlx_loop(super->win->mlx);
		}
		while (r->x < r->width)
		{
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
			r->x++;
			r->z++;
		if ((r->z) % ((r->zmax / 1000) == 0 ? 1 : (r->zmax / 1000))  == 0)
		{

				(loading_screen(super->win, (float)r->z / (float)r->zmax));
			return ;
		}



		}
		r->y++;
		r->x = 0;
	}

	apply_antiaaaliasing(super->win);
	mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img, 0, 0);
	super->render->state = 7;
}

int		rt_loop(t_super *super)
{
	if (super->render->state == 1)
		r_render_setup(super);
	else if (super->render->state == 2)
	//	r_render_tour(super);
		r_render_tour_phase_1(super);
	else if (super->render->state == 3)
	{
		super->render->x_tmp = 0;
		super->render->y_tmp = 0;
		super->render->state = 4;
	}
	else if (super->render->state == 4)
	{

		r_render_tour_phase_2(super);
	}
	else if (super->render->state == 5)
	{
		super->render->x_tmp = 0;
		super->render->y_tmp = 0;
		super->render->state = 6;
	}
	else if (super->render->state == 6)
	{

		r_render_tour_phase_3(super);
	}



	return (0);
}





void	r_render(t_super *super)
{

	t_render		*r;

	r = super->render;

//	raydir = new_params_vec(0, 0, 0);
//	rayorig = new_params_vec(0, 0, 0);
	r->width = X_IMG;
	r->height = Y_IMG;
	r->invWidth = 1.0 / (float)r->width;
	r->invHeight = 1.0 / (float)r->height;
	r->fov = 30;
	r->aspectratio = (float)r->width / (float)r->height;
	r->angle = tan(M_PI * 0.5 * r->fov / 180.);
	r->y = 0;

	super->trace = setup_trace();
	while (r->y < r->height)
	{
		if (r->y == 55 && 0)
		{
			test_img(super->win);
			mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img2, 0, 0);

	mlx_loop(super->win->mlx);
		}
		r->x = 0;
		while (r->x < r->width)
		{
			r->xx = (2 * ((r->x + 0.5) * r->invWidth) - 1) * r->angle * r->aspectratio;
			r->yy = (1 - 2 * ((r->y + 0.5) * r->invHeight)) * r->angle;
			push_params_vec(r->xx, r->yy, -1, r->raydir);
			reset_trace(super->trace);
	//		push_params_vec(xx, yy, -1, datrace->raydir);
			//		printf("x = %f, y = %f, z = %f	", raydir.x, raydir.y, raydir.z);
			normalize_vec(r->raydir);

		//	img_add_px(win, vec_to_color(new_params_vec(0.22, (float)y / (float)Y_WIN ,(float)x / (float)X_WIN)), x, y);

			img_add_px(super->win, vec_to_color(trace(r->rayorig, r->raydir, 0, super->list, super->trace)), r->x, r->y);
			r->x++;
		}
		r->y++;
	}
}


int		main(int argc, char **argv)
{
//	t_spher		*sphere;
//	t_list		*list;
//	t_list		*tmp;
//	t_win		*win;
	t_super		*super;

	super = setup_super();
	super->trace->test = 1;
	//	if ((win = (t_win*)malloc(sizeof(*win))) == NULL)
//		return (0);
//	if ((sphere = (t_spher*)malloc(sizeof(t_spher))) == NULL)
//		return (0);
	if (argc == 2)
		super->list = rt_parser_main(argc, argv);
//	sphere->pos = new_params_vec(0.0, 0.0, -20);
//	sphere->radius = 2;
//	sphere->color = new_params_vec(1.0, 0.32, 0.36);
//	sphere->refl = 1;
//	sphere->trans = 0.5;
//	sphere->emi = new_params_vec(0, 0, 0);
//	sphere->ps = new_params_pspher(2, 1, 0.5);
//	sphere = new_params_spher(new_params_vec(0.0, 0.0, -20), sphere->color = new_params_vec(1.0, 0.32, 0.36),  new_params_vec(0, 0, 0),new_params_pspher(2, 1, 0.5));
//	list = ft_lstnew_2(new_params_spher(new_params_vec(0.0, 0.0, -20),
//			new_params_vec(1.0, 0.32, 0.36) ,new_params_pspher(2, 1, 0.5)), 1000);
//	test_list(list);
	printf("ewfwegerhrhtsrt\n");
//	sphere->pos = new_params_vec(5.0, -3.0, -15);
//	sphere->radius = 2;
//	sphere->color = new_params_vec(1.0, 0.32, 0.36);
//	sphere->refl = 1;
//	sphere->trans = 0.5;
//	sphere->emi = new_params_vec(0, 0, 0);
//	tmp = ft_lstnew_2(new_params_spher(new_params_vec(5.0, -3.0, -15.0),
//			new_params_vec(1.0, 0.32, 0.36),  new_params_pspher(2, 1, 0.5)), sizeof(void*));
//	test_list(tmp);
//	ft_lstadd_2(&list, tmp);
	super->win->mlx = mlx_init();
	ft_putstr("ewfewqgrtrwhsyefweef\n");
	super->win->win = mlx_new_window(super->win->mlx, X_WIN, Y_WIN, "RT Mamene");
	if (1)
		super->win->img = mlx_new_image(super->win->mlx, X_IMG, Y_IMG);
	else
		super->win->img = mlx_new_image(super->win->mlx, X_WIN * 2, Y_WIN * 2);

	super->win->img2 = mlx_new_image(super->win->mlx, X_WIN / 2, 25);
	super->win->img3 = mlx_new_image(super->win->mlx, X_WIN, Y_WIN);
	super->win->addr = mlx_get_data_addr(super->win->img, &super->win->bpp, &super->win->sizeline, &super->win->endian);
	super->win->addr2 = mlx_get_data_addr(super->win->img2, &super->win->bpp2, &super->win->sizeline2, &super->win->endian2);
	super->win->addr3 = mlx_get_data_addr(super->win->img3, &super->win->bpp3, &super->win->sizeline3, &super->win->endian3);
//	test_img(super->win);
	//render(sphere, win, list);

//		r_render(super);
//	apply_antiaaaliasing(super->win);

//	test_list(super->list);
//	test_color();

//	mlx_put_image_to_window(super->win->mlx, super->win->win, super->win->img, 0, 0);

	mlx_key_hook(super->win->win, key_hook, &super->win);
	mlx_hook(super->win->win, 17, (1L << 17), rt_close, NULL);
	mlx_loop_hook(super->win->mlx, rt_loop, super);
	mlx_loop(super->win->mlx);
	return (0);
}
