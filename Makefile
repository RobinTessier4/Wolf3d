# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebui <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 21:53:40 by alebui            #+#    #+#              #
#    Updated: 2019/05/15 15:58:09 by alebui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc -Wall -Wextra -Werror
HEAD = -I includes -I libft/includes
FLAGS = -Wall -Wextra -Werror
LINK = -L ./libft -lft -L /usr/X11/lib -lX11 -L /usr/X11/lib -lXext -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC_FILES =	main.c \
			key_hook.c \
			mouse_hook.c \
			wolf.c \
			init_env.c \
			image.c \
			draw_grid.c \
			parse.c \
			read_map.c \
			raycasting.c \
			error.c \
			utils.c \
			vector.c \
			texture.c \
			clean.c 


OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all : objs $(NAME)

objs:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(HEAD) -c $< -o $@
	@echo "\033[32m["$(NAME)"] compilation de "$@"...\033[0m"

$(NAME): $(OBJ) $(SRC)
	@make -C libft
	@make -C minilibx
	@echo "\033[32m["$(NAME)"] compilation de "$(NAME)"...\033[0m"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LINK)

clean:
	@make -C libft clean
	@make -C minilibx clean
	@echo "\033[31m["$(NAME)"] suppression des objets...\033[0m"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft fclean
	@echo "\033[31m["$(NAME)"] suppression de "$(NAME)"...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
