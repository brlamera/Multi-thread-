# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 01:39:06 by juthomas          #+#    #+#              #
#    Updated: 2017/10/17 01:31:14 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Name of Project

NAME = libft.a

## Color for compilating (pink)

COLOR = \0033[3;35m

## Compilating Utilities

CFLAGS = #-Wall -Wextra -Werror -g -I libft.h

## List of Functions

SRC_FT = ./ft_isdigit ./ft_isalnum ./ft_isascii \
./ft_atoi ./ft_isalpha ./ft_strcat ./ft_strcmp \
./ft_strcpy ./ft_strdup ./ft_strlcat ./ft_strlen ./ft_strncat \
./ft_strncmp ./ft_strncpy ./ft_strnstr \
./ft_strstr ./ft_isprint ./ft_toupper ./ft_tolower \
./ft_strchr ./ft_strrchr ./ft_bzero ./ft_memset ./ft_memcpy \
./ft_memccpy ./ft_memmove ./ft_memchr ./ft_itoa ./ft_lstadd \
./ft_lstdel ./ft_lstdelone ./ft_lstiter ./ft_lstmap ./ft_lstnew \
./ft_memalloc ./ft_memdel ./ft_putchar ./ft_putchar_fd ./ft_putendl \
./ft_putendl_fd ./ft_putnbr ./ft_putnbr_fd ./ft_putstr \
./ft_putstr_fd ./ft_strclr ./ft_strdel ./ft_strequ ./ft_striter \
./ft_striteri ./ft_strjoin ./ft_strmap ./ft_strmapi \
./ft_strnequ ./ft_strnew ./ft_strsplit ./ft_strsub ./ft_strtrim \
./ft_memcmp ./ft_putbit ./ft_itoa_base ./ft_atoi_base \
./ft_putnbr_base ./ft_convert_base

## List of Utilities

OBJ = $(SRC_FT:%=%.o)
SRC = $(SRC_FT:%=%.c)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[0;37m"

#$(NAME): $(SRC)
#	@$(MAKE) -j -s $(OBJ)
#	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[0;37m"
#	@make -j -s -C $(LIB_DIR)
#	@$(CC) $(OBJ) -o $@
#	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[0;37m"

$(NAME): $(SRC)
	@gcc -c $(CFLAGS) $(SRC)
	@echo "\\0033[1;34mSource created\\0033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\\0033[0;32mLibft created\\0033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[0;37m"

re: fclean all

norme:
	@norminette $(SRC) libft.h

.PHONY: all clean fclean re norme
