/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:23:06 by juthomas          #+#    #+#             */
/*   Updated: 2018/03/20 02:55:23 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		rt_parser_no_space(char *str, int i)
{
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	printf("space = %d\n", i);
	return (i);
}

int		rt_parser_balise_name(char *str, int i, int *state)
{
	if (ft_strncmp(&str[i], "SCN", 3) == 0)
	{
		printf("//////////////////////////////////////////yolo\n");
		*state = 4;
	}
	else if (ft_strncmp(&str[i], "/", 1) == 0)
	{
		printf(":::::::::::::::::::::::::::::::::::::END OF BALISE\n");
		*state = 0;
	}
	else if (ft_strncmp(&str[i], "camera(s)", 9) == 0)
	{
		*state = 1;
	}
	else if (ft_strncmp(&str[i], "lightspot(s)", 12) == 0)
	{
		*state = 2;
	}
	else if (ft_strncmp(&str[i], "objet(s)", 8) == 0)
	{
		*state = 3;
	}
	else
		printf("....................................NEW BALISE\n");
	while (str[i] != '>' && str[i] != '\0')
		i++;
	printf("len = %d\n", i);
//	printf("yola\n");
	return (i);
}

int		rt_parser_go_next_number(char *str, int i)
{
	int		tmp;
	
	tmp = i;
	while (((str[tmp] >= '0' && str[tmp] <= '9') || str[tmp] == '.' || str[tmp] == '-'))
		tmp++;
	printf("|||||||||||||||||| %c ||||||||||||||", str[tmp]);
	if (str[tmp] != ' ' && str[tmp] != '}' && tmp == i)
		return (-1);
	while (str[tmp] == ' ')
		tmp++;
	printf("\n\n\n\n\n");
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '}'))
		return (-1);
	return (tmp);
}

int		rt_parser_stock_vec(char *str, t_vec *vec, int *nb, int dec)
{
	int		i;
	int		nu_of_params;
//	t_vec	*vec;

//	if ((vec = (t_vec*)malloc(sizeof(*vec))) == NULL)
//		exit(-1);
	nu_of_params = 0;
	i = *nb + dec;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ' ' || str[i] == '-'))
	{
//		vec->x = ft_adolphe(&str[i]);
		if (nu_of_params == 0)
		{
			vec->x = ft_adolphe(&str[i]);
			printf("@@@@@@ vec->x %f\n", ft_adolphe(&str[i]));
		}
		else if (nu_of_params == 1)
		{
			vec->y = ft_adolphe(&str[i]);
			printf("@@@@@@ vec->y %f\n", ft_adolphe(&str[i]));
		}
		else if (nu_of_params == 2)
		{
			vec->z = ft_adolphe(&str[i]);
			printf("@@@@@@ vec->z %f\n", ft_adolphe(&str[i]));
		}
		if ((i = rt_parser_go_next_number(str, i)) == -1)
			printf("\n!!!!!!!!!!!!!!failure!!!!!!!!!!!!!!!\n");
		nu_of_params++;
		//i++;
	}
	printf("voilaaaaa :::: %c :::::", str[i]);
	printf("nu_of_params %d\n", nu_of_params);
	*nb = i + 1;
	if (str[i] != '}' || nu_of_params != 3)
		return (-1);
//	ret = vec;

	printf("vector stocked X:%f\n", vec->x);
	printf("vector stocked Y:%f\n", vec->y);
	printf("vector stocked Z:%f\n", vec->z);
	return (0);
}

int		rt_parser_is_correct(char *str, char *ac, int len)
{
	int		i;
	int		u;
	int		lenac;
	int		ok;

	ok = 1;
	u = 0;
	i = 0;
	lenac = ft_strlen(ac);
	while (i < len)
	{
		ok = 1;
		u = 0;
		while (u < lenac && ok)
		{
			if (str[i] == ac[u])
				ok = 0;
			u++;
		}
		if (ok)
			return (0);
		i++;
	}
	return (1);
}

int		rt_parser_stock_color(char *str, t_vec *vec, int *nb, int dec)
{
	int				i;
	int				nu_of_params;
	unsigned int	color;
//	t_vec	*vec;

//	if ((vec = (t_vec*)malloc(sizeof(*vec))) == NULL)
//		exit(-1);
	nu_of_params = 0;
	i = *nb + dec;
	if (ft_strncmp(&str[i], "0X", 2) && rt_parser_is_correct(&str[i + 2], "0123456789ABCDEF", 6))
	{
		color = ft_atoi_base(&str[i + 2], "0123456789ABCDEF");
		printf("la couleur :%x\n", ft_atoi_base(&str[i + 2], "0123456789ABCDEF"));
	}
	else if (ft_strncmp(&str[i], "0x", 2) && rt_parser_is_correct(&str[i + 2], "0123456789ABCDEF", 6))
	{
		color = ft_atoi_base(&str[i + 2], "0123456789ABCDEF");
		printf("la couleur :%x\n", ft_atoi_base(&str[i + 2], "0123456789ABCDEF"));
	}
	else if (ft_strncmp(&str[i], "0X", 2) && rt_parser_is_correct(&str[i + 2], "0123456789abcdef", 6))
	{
		color = ft_atoi_base(&str[i + 2], "0123456789abcdef");
		printf("la couleur :%x\n", ft_atoi_base(&str[i + 2], "0123456789abcdef"));
	}
	else if (ft_strncmp(&str[i], "0x", 2) && rt_parser_is_correct(&str[i + 2], "0123456789abcdef", 6))
	{
		color = ft_atoi_base(&str[i + 2], "0123456789abcdef");
		printf("la couleur :%x\n", ft_atoi_base(&str[i + 2], "0123456789abcdef"));
	}
	else
		return (-1);

//printf("la couleur :%x\n"
	printf("la couleur stocked:%x\n", color);

	printf("PUUUUUTTTEUUUH \"%s\"\n", &str[i + 2]);
	if (str[i + 8] != ')')
		return (-1);
	vec->x = color / 256 / 256 % 256;
	vec->y = color / 256 % 256;
	vec->z = color % 256;
	if (NORM_COLOR == 1)
	{
		vec->x /= 255;
		vec->y /= 255;
		vec->z /= 255;
	}
	
	printf("la couleur stocked R:%f\n", vec->x);
	printf("la couleur stocked G:%f\n", vec->y);
	printf("la couleur stocked B:%f\n", vec->z);
	
	*nb = i + 9;
	return (0);
}


int		rt_parser_go_next_number_2(char *str, int i)
{
	int		tmp;
	
	tmp = i;
	while (((str[tmp] >= '0' && str[tmp] <= '9') || str[tmp] == '.' || str[tmp] == '-'))
		tmp++;
	printf("|||||||||||||||||| %c ||||||||||||||", str[tmp]);
	if (str[tmp] != ' ' && str[tmp] != ')' && tmp == i)
		return (-1);
	while (str[tmp] == ' ')
		tmp++;
	printf("\n\n\n\n\n");
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == ')'))
		return (-1);
	return (tmp);
}




int		rt_parser_stock_number(char *str, float *nu, int *nb, int dec)
{
	int		i;
	int		tmp;

	i = *nb + dec;
	tmp = i;

	if ((i = rt_parser_go_next_number_2(str, i)) == -1)
		exit(-1);
	*nu = ft_adolphe(&str[tmp]);
	printf("number stocked == %f\n", *nu);
	*nb = i + 1;

	return (0);
}

int		stock_triangle(t_triangle *triangle, char *str, int *nb)
{
	int		state;
	int		i;

	state = -1;
	i = *nb;

//	printf("str == \"%s\"", &str[i]);
	if (ft_strncmp(&str[i], "O1{", 3) == 0 || ft_strncmp(&str[i], "o1{", 3) == 0)
		state = rt_parser_stock_vec(str, triangle->p1, nb, 3);
	else if (ft_strncmp(&str[i], "O2{", 3) == 0 || ft_strncmp(&str[i], "o2{", 3) == 0)
		state = rt_parser_stock_vec(str, triangle->p2, nb, 3);
	else if (ft_strncmp(&str[i], "O3{", 3) == 0 || ft_strncmp(&str[i], "o3{", 3) == 0)
		state = rt_parser_stock_vec(str, triangle->p3, nb, 3);



//	else if (ft_strncmp(&str[i], "Rayon(", 6) == 0 || ft_strncmp(&str[i], "rayon(", 6) == 0)
//		state = rt_parser_stock_number(str, &spher->pspher->radius, nb, 6);

	else if (ft_strncmp(&str[i], "Couleur(", 8) == 0 || ft_strncmp(&str[i], "couleur(", 8) == 0)
		state = rt_parser_stock_color(str, triangle->color, nb, 8);

	else if (ft_strncmp(&str[i], "Reflexion(", 10) == 0 || ft_strncmp(&str[i], "reflexion(", 10) == 0)
		state = rt_parser_stock_number(str, &triangle->pbas->refl, nb, 10);
	else if (ft_strncmp(&str[i], "Opacity(", 8) == 0
			|| ft_strncmp(&str[i], "opacity(", 8) == 0)
		state = rt_parser_stock_number(str, &triangle->pbas->opac, nb, 8);
	else
		state = 1;

	return (state);
}



int		stock_spher(t_spher *spher, char *str, int *nb)
{
	int		state;
	int		i;

	state = -1;
	i = *nb;

//	printf("str == \"%s\"", &str[i]);
	if (ft_strncmp(&str[i], "Origine{", 8) == 0 || ft_strncmp(&str[i], "origine{", 8) == 0)
		state = rt_parser_stock_vec(str, spher->pos, nb, 8);
	else if (ft_strncmp(&str[i], "Rayon(", 6) == 0 || ft_strncmp(&str[i], "rayon(", 6) == 0)
		state = rt_parser_stock_number(str, &spher->pspher->radius, nb, 6);
	else if (ft_strncmp(&str[i], "Couleur(", 8) == 0 || ft_strncmp(&str[i], "couleur(", 8) == 0)
		state = rt_parser_stock_color(str, spher->color, nb, 8);
	else if (ft_strncmp(&str[i], "Reflexion(", 10) == 0 || ft_strncmp(&str[i], "reflexion(", 10) == 0)
		state = rt_parser_stock_number(str, &spher->pspher->refl, nb, 10);
	else if (ft_strncmp(&str[i], "Opacity(", 8) == 0
			|| ft_strncmp(&str[i], "opacity(", 8) == 0)
		state = rt_parser_stock_number(str, &spher->pspher->opac, nb, 8);
	else
		state = 1;

	return (state);
}


int		stock_lpsher(t_lspher *spher, char *str, int *nb)
{
	int		state;
	int		i;

	state = -1;
	i = *nb;

//	printf("str == \"%s\"", &str[i]);
	if (ft_strncmp(&str[i], "Origine{", 8) == 0 || ft_strncmp(&str[i], "origine{", 8) == 0)
		state = rt_parser_stock_vec(str, spher->pos, nb, 8);
	else if (ft_strncmp(&str[i], "Rayon(", 6) == 0 || ft_strncmp(&str[i], "rayon(", 6) == 0)
		state = rt_parser_stock_number(str, &spher->lpspher->radius, nb, 6);
	else if (ft_strncmp(&str[i], "Couleur(", 8) == 0 || ft_strncmp(&str[i], "couleur(", 8) == 0)
		state = rt_parser_stock_color(str, spher->color, nb, 8);
	else if (ft_strncmp(&str[i], "Emission(", 9) == 0 || ft_strncmp(&str[i], "emission(", 9) == 0)
		state = rt_parser_stock_number(str, &spher->lpspher->emi, nb, 9);
	else
		state = 1;

	return (state);
}



void	rt_parser_objtype_lspher_setup(t_lspher *spher)
{
	spher->pos->x = 0;
	spher->pos->y = 0;
	spher->pos->z = 0;
	spher->color->x = 0;
	spher->color->y = 0;
	spher->color->z = 0;
	spher->lpspher->radius = 0;
	spher->lpspher->emi = 0;
}

char	rt_parser_objtype_lspher(char *str, void **addr, char type)
{
	int		i;
	int		state;
	t_lspher		*spher;
	t_lspher		*tmp;

	state = 0;
	i = 0;
	if ((spher = (t_lspher*)malloc(sizeof(*spher))) == NULL)
		exit(-1);
	if ((spher->lpspher = (t_lpspher*)malloc(sizeof(*spher->lpspher))) == NULL)
		exit(-1);
	if ((spher->pos = (t_vec*)malloc(sizeof(*spher->pos))) == NULL)
		exit(-1);
	if ((spher->color = (t_vec*)malloc(sizeof(*spher->color))) == NULL)
		exit(-1);
	rt_parser_objtype_lspher_setup(spher);
	while (str[i] != '\0' && state == 0)
	{
		i = rt_parser_no_space(str, i);


			printf("{{{%s}}}\n\n", &str[i]);
			if ((state = stock_lpsher(spher, str, &i)) == -1)
				printf("\nexit\n");
				//	exit(-1);
	//	i++;
	}
				printf("1pos = x:%f y:%f z%f\n", spher->pos->x, spher->pos->y, spher->pos->z);
				printf("color = r:%f g:%f b:%f\n", spher->color->x, spher->color->y, spher->color->z);
				printf("radius = %f \n", spher->lpspher->radius);
				printf("emission = %f \n", spher->lpspher->emi);
	*addr = spher;
	tmp = *addr;
				printf("2pos = x:%f y:%f z%f\n", tmp->pos->x, tmp->pos->y, tmp->pos->z);
				printf("color = r:%f g:%f b:%f\n", tmp->color->x, tmp->color->y, tmp->color->z);
				printf("radius = %f \n", tmp->lpspher->radius);
				printf("emission = %f \n", tmp->lpspher->emi);
	return (type);
}

void	rt_parser_objtype_spher_setup(t_spher *spher)
{
	spher->pos->x = 0;
	spher->pos->y = 0;
	spher->pos->z = 0;
	spher->color->x = 0;
	spher->color->y = 0;
	spher->color->z = 0;
	spher->pspher->radius = 0;
	spher->pspher->refl = 0;
	spher->pspher->opac = 0;
}

void	rt_parser_objtype_triangle_setup(t_triangle *triangle)
{
	triangle->p1->x = 0;
	triangle->p1->y = 0;
	triangle->p1->z = 0;

	triangle->p2->x = 0;
	triangle->p2->y = 0;
	triangle->p2->z = 0;

	triangle->p3->x = 0;
	triangle->p3->y = 0;
	triangle->p3->z = 0;


	triangle->color->x = 0;
	triangle->color->y = 0;
	triangle->color->z = 0;
	
	triangle->pbas->refl = 0;
	triangle->pbas->opac = 0;
}

// char	rt_parser_objtype_spher(char *str, void **addr, char type)

char	rt_parser_objtype_triangle(char *str, void **addr, char type)//todo
{
	int		i;
	int		state;
	t_triangle		*triangle;
	t_triangle		*tmp;

	state = 0;
	i = 0;
	if ((triangle = (t_triangle*)malloc(sizeof(*triangle))) == NULL)
		exit(-1);
	if ((triangle->pbas = (t_pbasic*)malloc(sizeof(*triangle->pbas))) == NULL)
		exit(-1);
	if ((triangle->p1 = (t_vec*)malloc(sizeof(*triangle->p1))) == NULL)
		exit(-1);
	if ((triangle->p2 = (t_vec*)malloc(sizeof(*triangle->p2))) == NULL)
		exit(-1);
	if ((triangle->p3 = (t_vec*)malloc(sizeof(*triangle->p3))) == NULL)
		exit(-1);
	if ((triangle->color = (t_vec*)malloc(sizeof(*triangle->color))) == NULL)
		exit(-1);



	rt_parser_objtype_triangle_setup(triangle);
	while (str[i] != '\0' && state == 0)
	{
		i = rt_parser_no_space(str, i);


			printf("{{{%s}}}\n\n", &str[i]);
			if ((state = stock_triangle(triangle, str, &i)) == -1)
				printf("\nexit\n");
				//	exit(-1);
	//	i++;
	}
				printf("1_1pos = x:%f y:%f z%f\n", triangle->p1->x, triangle->p1->y, triangle->p1->z);
				printf("1_2pos = x:%f y:%f z%f\n", triangle->p2->x, triangle->p2->y, triangle->p2->z);
				printf("1_3pos = x:%f y:%f z%f\n", triangle->p3->x, triangle->p3->y, triangle->p3->z);
				
				printf("1_color = r:%f g:%f b:%f\n", triangle->color->x, triangle->color->y, triangle->color->z);
//				printf("radius = %f \n", spher->pspher->radius);
				printf("1_reflexion = %f \n", triangle->pbas->refl);
				printf("1_opacity = %f \n", triangle->pbas->opac);
	*addr = triangle;
	tmp = *addr;
				printf("2_1pos = x:%f y:%f z%f\n", tmp->p1->x, tmp->p1->y, tmp->p1->z);
				printf("2_2pos = x:%f y:%f z%f\n", tmp->p2->x, tmp->p2->y, tmp->p2->z);
				printf("2_3pos = x:%f y:%f z%f\n", tmp->p3->x, tmp->p3->y, tmp->p3->z);
				
				printf("2_color = r:%f g:%f b:%f\n", tmp->color->x, tmp->color->y, tmp->color->z);
//				printf("radius = %f \n", spher->pspher->radius);
				printf("2_reflexion = %f \n", tmp->pbas->refl);
				printf("2_opacity = %f \n", tmp->pbas->opac);
			




	return (type);
}


char	rt_parser_objtype_spher(char *str, void **addr, char type)
{
	int		i;
	int		state;
	t_spher		*spher;
	t_spher		*tmp;

	state = 0;
	i = 0;
	if ((spher = (t_spher*)malloc(sizeof(*spher))) == NULL)
		exit(-1);
	if ((spher->pspher = (t_pspher*)malloc(sizeof(*spher->pspher))) == NULL)
		exit(-1);
	if ((spher->pos = (t_vec*)malloc(sizeof(*spher->pos))) == NULL)
		exit(-1);
	if ((spher->color = (t_vec*)malloc(sizeof(*spher->color))) == NULL)
		exit(-1);
	rt_parser_objtype_spher_setup(spher);
	while (str[i] != '\0' && state == 0)
	{
		i = rt_parser_no_space(str, i);


			printf("{{{%s}}}\n\n", &str[i]);
			if ((state = stock_spher(spher, str, &i)) == -1)
				printf("\nexit\n");
				//	exit(-1);
	//	i++;
	}
				printf("1pos = x:%f y:%f z%f\n", spher->pos->x, spher->pos->y, spher->pos->z);
				printf("color = r:%f g:%f b:%f\n", spher->color->x, spher->color->y, spher->color->z);
				printf("radius = %f \n", spher->pspher->radius);
				printf("reflexion = %f \n", spher->pspher->refl);
				printf("opacity = %f \n", spher->pspher->opac);
	*addr = spher;
	tmp = *addr;
				printf("2pos = x:%f y:%f z%f\n", tmp->pos->x, tmp->pos->y, tmp->pos->z);
				printf("color = r:%f g:%f b:%f\n", tmp->color->x, tmp->color->y, tmp->color->z);
				printf("radius = %f \n", tmp->pspher->radius);
				printf("reflexion = %f \n", tmp->pspher->refl);
				printf("opacity = %f \n", tmp->pspher->opac);
	return (type);
}

char	rt_parser_objtype(char *str,  void *addr)
{
	char	type;

	if (ft_strncmp(str, "Sphere:", 7) == 0 || ft_strncmp(str, "sphere:", 7) == 0)
		type = 's';
	else if (ft_strncmp(str, "Cylindre", 8) == 0
			|| ft_strncmp(str, "cylindre", 8) == 0)
		type = 'c';
	else if (ft_strncmp(str, "Cone", 4) == 0 || ft_strncmp(str, "cone", 4) == 0)
		type = 'k';
	else if (ft_strncmp(str, "Plan", 4) == 0 || ft_strncmp(str, "plan", 4) == 0)
		type = 'p';
	else if (ft_strncmp(str, "Triangle:", 9) == 0
			|| ft_strncmp(str, "triangle:", 9) == 0)
		type = 't';
	else if (ft_strncmp(str, "Disque", 6) == 0
			|| ft_strncmp(str, "disque", 6) == 0)
		type = 'd';
	else
		type = 0;

	return (type);
}


t_type	*rt_parser_objtype_done(char *str,  void *addr, char type)
{
	t_type *typ;
	t_spher *spher;
	t_triangle *triangle;

	if ((typ = (t_type*)malloc(sizeof(*typ))) == NULL)
		exit(-1);
//	if ((typ->obj = (void*)malloc(sizeof(*typ->obj))) == NULL)
//		exit(-1);

	if (type == 's')
	{
		typ->name = rt_parser_objtype_spher(&str[7], &typ->obj, 's');
		printf("addr : %d\n", &typ->obj);
		if (typ->obj)
		{
		spher = typ->obj;
		printf("pos = x:%f y:%f z%f\n", spher->pos->x, spher->pos->y, spher->pos->z);
		printf("color = r:%f g:%f b:%f\n", spher->color->x, spher->color->y, spher->color->z);
		printf("radius = %f \n", spher->pspher->radius);
		printf("reflexion = %f \n", spher->pspher->refl);
		printf("opacity = %f \n", spher->pspher->opac);
		}
	}
	else if (type == 't')
	{
		typ->name = rt_parser_objtype_triangle(&str[9], &typ->obj, 't');
		printf("addr : %d\n", &typ->obj);
		if (typ->obj)
		{
		triangle = typ->obj;
		printf("p1 = x:%f y:%f z%f\n", triangle->p1->x, triangle->p1->y, triangle->p1->z);
		printf("p2 = x:%f y:%f z%f\n", triangle->p2->x, triangle->p2->y, triangle->p2->z);
		printf("p3 = x:%f y:%f z%f\n", triangle->p3->x, triangle->p3->y, triangle->p3->z);

		printf("color = r:%f g:%f b:%f\n", triangle->color->x, triangle->color->y, triangle->color->z);
		
		printf("reflexion = %f \n", triangle->pbas->refl);
		printf("opacity = %f \n", triangle->pbas->opac);
		}
	}








	printf("testtesttesttesttesttest %c\n", typ->name);
	return (typ);
}


t_type	*rt_parser_lobjtype_done(char *str,  void *addr, char type)
{
	t_type *typ;
	t_lspher *spher;


	if ((typ = (t_type*)malloc(sizeof(*typ))) == NULL)
		exit(-1);
//	if ((typ->obj = (void*)malloc(sizeof(*typ->obj))) == NULL)
//		exit(-1);

	if (type == 's')
	{
		typ->name = rt_parser_objtype_lspher(&str[7], &typ->obj, 'S');
		printf("addr : %d\n", &typ->obj);
		if (typ->obj)
		{
		spher = typ->obj;
		printf("pos = x:%f y:%f z%f\n", spher->pos->x, spher->pos->y, spher->pos->z);
		printf("color = r:%f g:%f b:%f\n", spher->color->x, spher->color->y, spher->color->z);
		printf("radius = %f \n", spher->lpspher->radius);
		printf("emission = %f \n", spher->lpspher->emi);
		}
	}
	printf("testtesttesttesttesttest %c\n", typ->name);
	return (typ);
}



int		rt_parser_state(char *str, int state, int i)
{
	if (str[i] == '<')
	{	
		printf("hi\n");
		i++;	
		rt_parser_balise_name(str, i, &state);
	}
	return (state);
}

/*
**		state == 0 : il ne se passe rien
**		state == 1 : partie cameras
**		state == 2 : partie lumieres
**		state == 3 : partie objets
**		state == 4 : nouvelle scene
*/


void	test_obj(t_list *list)
{
	t_type *type;
	t_spher *spher;
	t_triangle *triangle;

	printf("[[[[[[[[[[[[[[[[[[[[SHOOOOOOOOOW BEGGGGIINNN]]]]]]]]]]]]]]]]]]]]]]]]\n");
	while (list)
	{

		if (list->content)
		{
			type = list->content;
			printf("[[[[[[[[[[[[[[[[[[[[CONTENT]]]]]]]]]]]]]]]]]]]]]]]] = %c\n", type->name);
			if (type->name == 's')
			{
				spher = type->obj;
				printf("pos = x:%f y:%f z:%f\n", spher->pos->x, spher->pos->y, spher->pos->z);
				printf("color = r:%f g:%f b:%f\n", spher->color->x, spher->color->y, spher->color->z);
				printf("radius = %f \n", spher->pspher->radius);
				printf("reflexion = %f \n", spher->pspher->refl);
				printf("opacity = %f \n", spher->pspher->opac);

			}
			else if (type->name == 't')
			{
				triangle = type->obj;
				printf("p1 = x:%f y:%f z%f\n", triangle->p1->x, triangle->p1->y, triangle->p1->z);
				printf("p2 = x:%f y:%f z%f\n", triangle->p2->x, triangle->p2->y, triangle->p2->z);
				printf("p3 = x:%f y:%f z%f\n", triangle->p3->x, triangle->p3->y, triangle->p3->z);

				printf("color = r:%f g:%f b:%f\n", triangle->color->x, triangle->color->y, triangle->color->z);
		
				printf("reflexion = %f \n", triangle->pbas->refl);
				printf("opacity = %f \n", triangle->pbas->opac);
			}


		}
		else 
			printf("non rien de rien\n");


		list = list->next;
	}

	printf("[[[[[[[[[[[[[[[[[[[[SHOOOOOOOOOW ENNNNNNDDDD]]]]]]]]]]]]]]]]]]]]]]]]\n");

}

t_type	*fonction_test(int i)
{
	t_type	 *type;

	if ((type = (t_type*)malloc(sizeof(*type))) == 0)
		exit(-1);
		printf("parsed\n");
	type->name = 'S';
	return (type);
}

void	ft_lstdellast(t_list **list, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = *list;
	while ((tmp)->next)
	{
		if (tmp->next->next == 0)
		{
			ft_memdel((void**)(tmp)->next);
			(tmp)->next = NULL;
			return ;
		}
		printf("GRAND TOUR RISMOOOW\n");
		(tmp) = (tmp)->next;
	}
//	del((*list)->content, (*list)->content_size);
	
}

t_list	*rt_parser_main(int argc, char **argv)
{
	int		fd;
	char*	line;
	t_list	*list;
	int		i;
	int		state;
	char	obj_name;
	i = 0;
	state = 0;
	void	*obj;

	obj = 0;
//	list = ft_lstnew_2()
	list = ft_lstnew(0, 0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
	//	state = 1;
		i = rt_parser_no_space(line, i);
		state = rt_parser_state(line, state, i);
		if (state == 2)
		{

			if ((obj_name = rt_parser_objtype(&line[i], obj)) != 0)
				ft_lstadd(&list, ft_lstnew(rt_parser_lobjtype_done(&line[i],  obj, obj_name), sizeof(t_type)));



		}
		else if (state == 3)
		{
			
		//	ft_lstadd(&list, ft_lstnew(fonction_test(i), sizeof(t_type)));
			if ((obj_name = rt_parser_objtype(&line[i], obj)) != 0)
				ft_lstadd(&list, ft_lstnew(rt_parser_objtype_done(&line[i],  obj, obj_name), sizeof(t_type)));
		}

		printf("\nname = %c\n", obj_name);
		if (state)
		{
			printf("\n\nstate = %d\n", state);
			printf("{{{%s}}}\n\n", &line[i]);
		}
	}
	ft_lstdellast(&list, 0);
	test_obj(list);
	return (list);
}





