# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 15:13:09 by alefebvr          #+#    #+#              #
#    Updated: 2018/03/17 16:46:14 by alefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ =  main.o draw_line.o read_file.o bresenham.o

SRC = $(OBJ:.o=.c)

LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
FLAGMLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(SRC) fdf.h
	make -C libft
	make -C minilibx_macos
	gcc $(FLAGS) $(SRC) $(FLAGMLX) $(LIBFT) -o $(NAME)
	rm -rf $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
