## Name of Project

NAME = wolf3d

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs
LIB_DIR = libft

## Compilating Utilities

FLAGS = -Wall -Wextra -Werror -Ofast
INC = $(INC_DIR:%=-I ./%)
LIB = -L $(LIB_DIR) -lft
MLX = ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
CC = clang $(FLAGS) $(INC)

## List of Functions

SRC_FT = wlf_main \
		 wlf_map_extract \
		 wlf_put_in_map \
		 wlf_start_aff \
		 mlx_pix_img \
		 wlf_init_all \
		 hook \
		 wlf_rendu \
		 wlf_minimap \
		 wlf_game \
		 wlf_load

## List of Utilities

OBJ = $(SRC_FT:%=$(OBJ_DIR)/%.o)
SRC = $(SRC_FT:%=$(SRC_DIR)/%.c)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[0;37m"

$(OBJ_DIR):
	@afplay file/rupee.mp3 &
	@mkdir -p $@
	@echo "$(COLOR)Creating    : \0033[0;32m$@\0033[0;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@
	@echo "$(COLOR)Compilating : \0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[0;37m"

$(NAME): $(OBJ_DIR) $(SRC)
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

norme:
	@norminette $(SRC) $(INC_DIR)/
	@make norme -C $(LIB_DIR)

.PHONY: all clean fclean re norme
