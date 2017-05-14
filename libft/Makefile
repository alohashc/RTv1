# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alohashc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 14:50:41 by alohashc          #+#    #+#              #
#    Updated: 2017/02/22 13:46:57 by alohashc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c \
	  ./ft_memchr.c ./ft_memcmp.c ./ft_strlcat.c ./ft_strlen.c ./ft_strdup.c \
	  ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strchr.c \
	  ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strncmp.c \
	  ./ft_atoi.c ./ft_isalpha.c ./ft_isalnum.c ./ft_isdigit.c ./ft_isascii.c \
	  ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memalloc.c ./ft_memdel.c \
	  ./ft_strdel.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strsub.c \
	  ./ft_strnew.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c \
	  ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_strrev.c \
	  ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr_fd.c ./ft_putnbr.c \
	  ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_countwords.c \
	  ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c \
	  ./ft_lstmap.c ./ft_strlcpy.c ./ft_strndup.c ./ft_swap.c ./get_next_line.c \
	  ./ft_atoi_hex.c

O_FILE = $(SRC:.c=.o)

INCLUDE = ./

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME): $(O_FILE)
	ar rc $(NAME) $(O_FILE)

clean:
	rm -rf $(O_FILE)

fclean: clean
	rm -rf $(NAME)

re: clean all
