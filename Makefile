# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/03/29 15:20:44 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Werror -Wextra -I includes

SRC = srcs/main.c \
	  srcs/calculations.c \
	  srcs/aux.c \
	  srcs/display.c \
	  srcs/movement.c \
	  srcs/parse.c \
	  srcs/key_binding.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h -lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
