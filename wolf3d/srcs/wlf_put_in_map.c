/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_put_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:43:59 by brlamera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		wlf_set_env(t_ptr *ptr)
{
	t_file	*sky;
	t_key	*key;
	t_file	*txt;

	sky = (t_file *)malloc(sizeof(t_file));
	init_skybox(sky, ptr);
	ptr->sky = sky;
	loading_file(ptr);
	wlf_initialis(ptr);
	txt = (t_file *)malloc(sizeof(t_file));
	init_text(txt, ptr);
	ptr->txt = txt;
	key = (t_key *)malloc(sizeof(t_key));
	init_key(key);
	ptr->key = key;
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dest;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[n])
	{
		dest[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		dest[n++] = s2[i];
		i++;
	}
	dest[n] = '\0';
	free(s1);
	free(s2);
	return (dest);
}

char		*wlf_extracting(int fd)
{
	char	*str;
	char	*buf;

	if (!(str = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (NULL);
	ft_memset(buf, '\0', 10001);
	ft_memset(str, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		if (!(str = ft_strjoin_free(str, buf)))
			return (NULL);
		if (!(buf = (char *)malloc(sizeof(char) * 10001)))
			return (NULL);
		ft_memset(buf, '\0', 10001);
	}
	free(buf);
	return (str);
}

int			**wlf_put_in_map(int **map, int fd, int mx, int my)
{
	t_stc	st;

	st.n = 0;
	st.i = 0;
	st.s = 0;
	if (!(st.str = wlf_extracting(fd)))
		return (NULL);
	while (st.str[st.i])
	{
		if (st.str[st.i] == '-' || (st.str[st.i] >= '0' && st.str[st.i] <= '9'))
		{
			map[st.n][st.s] = ft_atoi(&st.str[st.i]);
			while (st.str[st.i] && (st.str[st.i] >= '0' && st.str[st.i] <= '9'))
				st.i++;
		}
		if ((st.n == 0 || st.n == my - 1 || st.s == 0 || st.s == mx - 1)
			&& map[st.n][st.s] != 1)
			map[st.n][st.s] = 1;
		st.s++;
		st.n += (st.str[st.i] && st.str[st.i] == '\n' ? 1 : 0);
		st.s = (st.str[st.i] && st.str[st.i++] == '\n' ? 0 : st.s);
		st.i += (st.str[st.i] && st.str[st.i] == ' ' ? 1 : 0);
	}
	free(st.str);
	return (map);
}

void		mlx_put_line(t_ptr *ptr)
{
	t_line	l;

	l.dx = ABS(ptr->x1 - ptr->x0);
	l.sx = (ptr->x0 < ptr->x1 ? 1 : -1);
	l.dy = ABS(ptr->y1 - ptr->y0);
	l.sy = (ptr->y0 < ptr->y1 ? 1 : -1);
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		mlx_pix_img(ptr, ptr->x0, ptr->y0, ptr->colors);
		if (ptr->x0 == ptr->x1 && ptr->y0 == ptr->y1)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			ptr->x0 += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			ptr->y0 += l.sy;
		}
	}
}
