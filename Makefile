# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alohashc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 10:48:43 by alohashc          #+#    #+#              #
#    Updated: 2017/05/10 16:50:36 by alohashc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = ./main.c \
	  ./sphere.c \
	  ./vectors.c \
	  ./plane.c \
	  ./cylinder.c \
	  ./cone.c \
	  ./all_primitives.c

O_FILE = $(SRC:.c=.o)

INC = ./

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(O_FILE) rtv1.h
	make -C ./libft/
	gcc -o $(NAME) $(O_FILE) -L ./libft/ -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAGS) -I $(INC) -c $< 

clean:
	make clean -C ./libft/
	rm -rf $(O_FILE)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re: clean all
