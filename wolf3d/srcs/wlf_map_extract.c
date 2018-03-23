/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf_map_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <aancel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 02:49:45 by aancel            #+#    #+#             */
/*   Updated: 2017/11/01 18:43:57 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_count_s(char *str)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
			ft_error(0);
		if (str[i] == ' ' && str[i + 1] != '\n')
			s++;
		i++;
	}
	s++;
	return (s);
}

int		ft_isfullnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' '
			&& str[i] != '\0' && str[i] != '\n')
			return (-1);
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (-1);
		if (str[0] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int		wlf_check_file(int *l, int *a, int fd)
{
	char	*str1;
	char	*buf;

	if (!(str1 = (char *)malloc(sizeof(char) * 11)))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (-1);
	ft_memset(buf, '\0', 10001);
	ft_memset(str1, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		if (ft_isfullnum(buf))
			return (-1);
		if (!(str1 = ft_strjoin_free(str1, buf)))
			return (-1);
		if (!(buf = (char *)malloc(sizeof(char) * 10001)))
			return (-1);
		ft_memset(buf, '\0', 10001);
	}
	free(buf);
	if (ft_strlen(str1) < 10)
		return (-1);
	return (wlf_check_file2(&str1, l, a));
}

int		wlf_check_file2(char **str1, int *l, int *a)
{
	char	**map;
	int		i;

	map = ft_strsplit(*str1, '\n');
	i = 0;
	while (map[i])
	{
		if (*l == 0)
			*a = ft_count_s(map[i]);
		else
		{
			if (*a != ft_count_s(map[i]))
				return (-1);
		}
		if (ft_isfullnum(map[i]) == -1)
			return (-1);
		*l += 1;
		free(map[i]);
		i++;
	}
	free(*str1);
	free(map);
	return (0);
}

t_map	*wlf_map_extract(int fd, char *filename)
{
	int		l;
	int		a;
	t_map	*m;

	l = 0;
	m = NULL;
	if (wlf_check_file(&l, &a, fd) == -1)
		return (NULL);
	if (!(m = malloc(sizeof(t_map))))
		return (NULL);
	m->map = NULL;
	if (!(m->map = (int **)malloc(sizeof(int *) * l)))
		return (NULL);
	m->l = 0;
	while (m->l < l)
	{
		if (!(m->map[m->l++] = (int *)malloc(sizeof(int) * a)))
			return (NULL);
	}
	m->c = a;
	close(fd);
	fd = open(filename, O_RDONLY);
	if (!(m->map = wlf_put_in_map(m->map, fd, m->c, m->l)))
		return (NULL);
	return (m);
}
