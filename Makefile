# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 12:33:43 by armaxima          #+#    #+#              #
#    Updated: 2021/12/18 23:16:36 by armaxima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = philo

SRC = src/philo.c \
	src/ft_put.c \
	src/ft_check_argv.c \
	src/ft_atoi.c \
	src/ft_clear_av.c \
	src/ft_create_lst.c \
	src/ft_utils.c \
	src/ft_go.c

HEADER = includes/

OBJ = $(SRC:.c=.o)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)philo.h
	gcc $(FLAG) $(OBJ) -o $(NAME) -I includes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
