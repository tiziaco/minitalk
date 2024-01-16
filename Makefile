# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 18:33:34 by tiacovel          #+#    #+#              #
#    Updated: 2024/01/16 13:15:26 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
PRINTF_LIB	= src/printf/libftprintf.a

SRC_CLIENT = src/client.c src/utils.c
SRC_SERVER = src/server.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

RM		= rm -f
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = -I include

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
		@make -C src/printf
		$(CC) $(CFLAGS) $(OBJ_CLIENT) $(INCLUDE) $(PRINTF_LIB) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
		@make -C src/printf
		$(CC) $(CFLAGS) $(OBJ_SERVER) $(INCLUDE) $(PRINTF_LIB) -o $(NAME_SERVER)

clean:
		@make clean -C src/printf
		$(RM) $(OBJ_CLIENT)
		$(RM) $(OBJ_SERVER)

fclean: clean
		@make clean -C src/printf
		$(RM) $(NAME_CLIENT)
		$(RM) $(NAME_SERVER)
		$(RM) $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re
