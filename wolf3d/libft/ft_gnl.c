/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:15:34 by aancel            #+#    #+#             */
/*   Updated: 2017/01/10 13:25:35 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	gnl_reader(t_store *store, int fd)
{
	if (store->stock[fd] == NULL)
		store->stock[fd] = ft_strnew(1);
	while (!(ft_strchr(store->stock[fd], '\n')) &&
		(store->ret = read(fd, store->buf, BUFF_SIZE)) > 0)
	{
		store->buf[store->ret] = '\0';
		store->tmp = store->stock[fd];
		store->stock[fd] = ft_strjoin(store->stock[fd], store->buf);
		ft_strdel(&store->tmp);
	}
	ft_strdel(&store->buf);
}

int			get_next_line(const int fd, char **line)
{
	static t_store	store;

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFF_SIZE <= 0 ||
	BUFF_SIZE > MAX_INT || !(store.buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	gnl_reader(&store, fd);
	if (store.ret == -1)
		return (-1);
	*line = ft_strsub(store.stock[fd], 0, ft_strlenre(store.stock[fd], '\n'));
	if (ft_strchr(store.stock[fd], '\n'))
	{
		store.tmp = store.stock[fd];
		store.stock[fd] = ft_strdup(ft_strchr(store.stock[fd], '\n') + 1);
		ft_strdel(&store.tmp);
		return (1);
	}
	if (ft_strlenre(store.stock[fd], '\n') > 0)
	{
		store.stock[fd] = store.stock[fd] + ft_strlenre(store.stock[fd], '\n');
		return (1);
	}
	return (0);
}
