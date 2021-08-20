# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abambi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 00:26:48 by abambi            #+#    #+#              #
#    Updated: 2021/07/08 20:20:46 by abambi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	= client
SRC_C	= b_client.c c_utils.c
OBJ_C	= $(SRC_C:.c=.o)

SERVER	= server
SRC_S	= a_server.c c_utils.c
OBJ_S	= $(SRC_S:.c=.o)

INC = ./

CFLAGS	= -Wextra -Wall -Werror
CC		= gcc
RM		= rm -f

.PHONY: all clean fclean re

all:  $(CLIENT) $(SERVER)

$(CLIENT):	$(OBJ_C) minitalk.h Makefile
			$(CC) $(CFLAGS) $(OBJ_C) -I$(INC) -o $(CLIENT)

$(SERVER):	$(OBJ_S) minitalk.h Makefile
			$(CC) $(CFLAGS) $(OBJ_S) -I$(INC) -o $(SERVER)

clean:
	$(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all
