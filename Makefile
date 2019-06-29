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

NAME		= fractal
CFLAGS		= -o1 -o2 -o3 -Wall -Werror -Wextra
FILES		= *.c
INCLUDES	= /usr/local/include
LIBSLD		= -lSDL2 -lSDL2main

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(FILES) $(LIBSLD) -o $(NAME)

clean:
	rm -rf $(NAME)
	clear

fclean: clean

re: fclean all

rebuild: fclean rebuild_libft all

rebuild_libft:
	make re -C libft
	make clean -C libft