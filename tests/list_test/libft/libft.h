/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 02:00:40 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/23 11:23:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putnbr_base(int nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from,
					char *base_to);
int					ft_atoi_base(char *str, char *base);
char				*ft_itoa_base(int value, int base);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst,
					const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst,
					const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(char *src);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
int					ft_strlen(const char *str);
char				*ft_strncat(char *dest, char *src, int nb);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *str, char *to_find);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putbit(char c);
void				ft_strdel(char **as);
#endif
