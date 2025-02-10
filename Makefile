# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 17:49:51 by dicosta-          #+#    #+#              #
#    Updated: 2025/02/10 21:12:39 by dicosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC = push_swap.c stack_management.c aux.c movements.c sorting.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:

	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean

	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re