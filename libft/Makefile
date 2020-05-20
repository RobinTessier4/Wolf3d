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

NAME = libft.a

CC = gcc

HEAD = -I includes

AR = ar rc

FLAGS = -Wall -Wextra -Werror


OTHERS	=	others/ft_atoi.c \
			others/ft_atoi_base.c \
			others/ft_isalpha.c \
			others/ft_isdigit.c \
			others/ft_isalnum.c \
			others/ft_isascii.c \
			others/ft_isprint.c \
			others/ft_toupper.c \
			others/ft_tolower.c \
	  		others/ft_itoa.c \
			others/ft_ftoa.c \
			others/ft_power.c

STRS	=	str/ft_strlen.c \
			str/ft_strdup.c \
			str/ft_strcpy.c \
			str/ft_strncpy.c \
			str/ft_strcat.c \
			str/ft_strlcat.c \
			str/ft_strncat.c \
			str/ft_strlcat.c \
			str/ft_strchr.c \
			str/ft_strrchr.c \
			str/ft_strstr.c \
			str/ft_strnstr.c \
			str/ft_strcmp.c \
			str/ft_strncmp.c \
			str/ft_strnew.c \
			str/ft_strdel.c \
			str/ft_strclr.c \
			str/ft_striter.c \
			str/ft_striteri.c \
			str/ft_strmap.c \
			str/ft_strmapi.c \
			str/ft_strequ.c \
			str/ft_strnequ.c \
			str/ft_strsub.c \
			str/ft_strsubfree.c \
			str/ft_strjoin.c \
			str/ft_strjoin_free.c \
			str/ft_strtrim.c \
			str/ft_strsplit.c \
			str/ft_strsplit_multi.c

LST		=	lists/ft_lstiter.c \
			lists/ft_lstadd.c \
			lists/ft_lstdel.c \
			lists/ft_lstdelone.c \
			lists/ft_lstnew.c \
			lists/ft_lstmap.c \
			lists/ft_lstdup.c \
			lists/ft_lstfind.c \
			lists/ft_lstpushback.c

MEMS	=	memory/ft_bzero.c \
			memory/ft_memcmp.c \
			memory/ft_memccpy.c \
			memory/ft_memcpy.c \
			memory/ft_memchr.c \
			memory/ft_memset.c \
			memory/ft_memmove.c \
	   		memory/ft_memalloc.c \
	   		memory/ft_memdel.c

IO		=	io/ft_putchar.c \
			io/ft_putstr.c \
			io/ft_putendl.c \
			io/ft_putnbr.c \
			io/ft_putchar_fd.c \
			io/ft_putstr_fd.c \
			io/ft_putendl_fd.c \
			io/ft_putnbr_fd.c \
			io/get_next_line.c

TABS	=	tabs/ft_tabdel.c \
			tabs/ft_tabsub.c \
			tabs/ft_tablen.c \
			tabs/ft_tabdup.c

DRAW	=	draw/mlx.c \
			draw/img.c \
			draw/img_color.c \
			draw/drawline.c \
			draw/fill.c

SRCS = $(IO) $(MEMS) $(OTHERS) $(STRS) $(TABS) $(LST) $(DRAW)

OBJS = $(SRCS:.c=.o)

DRAWOBJ	= $(DRAW:.c=.o)

all: $(NAME)

draw: $(OBJ) $(DRAWOBJ)
	@echo "\033[32m["$(NAME)"] compilation de "$(NAME)"...\033[0m"
	@ar rc $(NAME) $(OBJ) $(DRAWOBJ)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEAD)

$(NAME): $(OBJS)
	@echo "\033[32m["$(NAME)"] compilation de "$(NAME)"...\033[0m"
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@echo "\033[31m["$(NAME)"] suppression des objets...\033[0m"
	rm -f $(OBJS)

fclean:	clean
	@echo "\033[31m["$(NAME)"] suppression de "$(NAME)"...\033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
