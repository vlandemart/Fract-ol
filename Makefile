#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njacobso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 16:28:47 by njacobso          #+#    #+#              #
#    Updated: 2019/05/06 20:12:55 by njacobso         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fdf
CFLAGS		= -o1 -o2 -o3 -Wall -Werror -Wextra
FILES		= *.c
LIBMLX		= ./minilibx -lmlx
LIBVGX		= ./libvgx -lvgx
LIBFT		= ./libft -lft
INCLUDES	= /usr/local/include
FRAMEWORKS	= -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I $(INCLUDES) $(FILES) -L $(LIBMLX) -L $(LIBVGX) -L $(LIBFT) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -rf $(NAME)
	clear

fclean: clean

re: fclean rebuild_libvgx all

rebuild: fclean rebuild_libft rebuild_libvgx all

rebuild_libvgx:
	make re -C libvgx
	make clean -C libvgx

rebuild_libft:
	make re -C libft
	make clean -C libft