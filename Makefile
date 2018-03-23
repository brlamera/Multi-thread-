# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brlamera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 05:50:28 by brlamera          #+#    #+#              #
#    Updated: 2018/03/14 16:19:36 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Name of Project

NAME = rtv1

## Color for compilating (pink)

COLOR = \0033[3;35m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs
LIB_DIR = libft

## Compilating Utilities

FLAGS = -Wall -Wextra #-g -fsanitize=address #-Wall -Wextra -Werror -g
INC = $(INC_DIR:%=-I ./%)
LIB = -L $(LIB_DIR) -lft
MLX = ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -Ofast
CC = clang $(FLAGS) $(INC)

## List of Functions

SRC_FT = rt get_next_line rt_parser ft_adolphe

## List of Utilities

OBJ = $(SRC_FT:%=$(OBJ_DIR)/%.o)
SRC = $(SRC_FT:%=$(SRC_DIR)/%.c)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[0;37m"

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(COLOR)Creating    :\t\0033[0;32m$@\0033[0;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/rtv1.h
	@$(CC) -c $< -o $@
	@echo "$(COLOR)Compilating :\t\0033[3;33m$(@:$(OBJ_DIR)/%=%)\0033[0;37m"

$(NAME): $(OBJ_DIR) $(SRC) $(INC_DIR)/rtv1.h
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[0;37m"
	@make -j -s -C $(LIB_DIR)
	@$(CC) $(LIB) $(OBJ) $(MLX) -o $@
	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[0;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[0;37m"

re: fclean all

pao: re
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[0;37m"

norme:
	@norminette $(SRC) $(INC_DIR)/

.PHONY: all clean fclean re norme
