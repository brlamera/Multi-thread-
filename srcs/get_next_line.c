/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:12:48 by juthomas          #+#    #+#             */
/*   Updated: 2016/12/08 15:25:24 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_fonc(int fd, char *ptr[1], char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		index;
	char	*c;
	char	*tmp;

	while (!(c = ft_strchr(*ptr, '\n')) &&
			(index = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[index] = '\0';
		tmp = *ptr;
		*ptr = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	if (index == -1)
		return (-1);
	if (!c && index == 0)
	{
		if (*ptr[0] == '\0')
			*line = ft_strdup("");
		return (0);
	}
	return (1);
}

static char	**ft_listing_fonc(int fd, char *ptr[1])
{
	static char	*lsting[2048];

	if (ptr != NULL)
		lsting[fd] = *ptr;
	*lsting = lsting[fd];
	return (lsting);
}

static int	get_next_line_tf(char **ptr, int fd, char **line)
{
	if (*ptr[0] == '\0')
	{
		ft_listing_fonc(fd, ptr);
		return (0);
	}
	*line = *ptr;
	ptr[0] = NULL;
	ft_listing_fonc(fd, ptr);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		**ptr;
	int			ret;
	char		*tmp;

	if (fd < 0 || fd == 1 || fd == 2 || fd > 2047 || BUFF_SIZE <= 0
			|| line == NULL)
		return (-1);
	ptr = ft_listing_fonc(fd, NULL);
	if (*ptr == NULL)
		*ptr = ft_strnew(1);
	if ((ret = ft_read_fonc(fd, ptr, line)) == 0)
		return (get_next_line_tf(ptr, fd, line));
	if (ret == -1)
	{
		ft_listing_fonc(fd, ptr);
		return (-1);
	}
	*line = ft_strsub(*ptr, 0, (ft_strchr(*ptr, '\n') - *ptr));
	tmp = *ptr;
	*ptr = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	ft_listing_fonc(fd, ptr);
	return (1);
}
