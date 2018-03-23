/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:31:12 by aancel            #+#    #+#             */
/*   Updated: 2016/11/22 22:50:49 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define ABS(x)		((x) < 0 ? -(x) : (x))
# define BUFF_SIZE 1000
# define MAX_FD 10000
# define MAX_INT 2147483647

typedef struct		s_store
{
	char	*stock[MAX_FD + 1];
	char	*buf;
	int		ret;
	char	*tmp;
}					t_store;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				**ft_create_tab(int i, int j);
void				ft_puttab(char **tab, int elem);
void				ft_puttab_fd(char **tab, int elem, int fd);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
int					ft_atoi(const char *str);
char				*ft_strcpy(char *dest, const char *src);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strstr(char *big, char *little);
char				**ft_strsplit(char const *s, char c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(char *big, char *little, size_t loc);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
char				*ft_strtrim(char *s);
int					ft_count_space(char const *str);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nouveu);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_count_word(char const *str, char c);
char				*ft_strrev(char *str);
int					get_next_line(int const fd, char **line);
size_t				ft_strlenre(const char *str, const char c);

#endif
