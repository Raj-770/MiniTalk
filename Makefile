# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 11:47:28 by rpambhar          #+#    #+#              #
#    Updated: 2023/11/18 12:13:42 by rpambhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ft_printf/libftprintf.a ft_printf/libft/libft.a
CLIENT = client
SERVER = server
SRC_C = client.c
SRC_S = server.c

all : $(CLIENT) $(SERVER) $(LIBFT)

$(CLIENT) : $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFTPRINTF) -o $(CLIENT)

$(SERVER) : $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFTPRINTF) -o $(SERVER)

clean :
	rm -f $(CLIENT)
	rm -f $(SERVER)

fclean : clean

re : fclean
	$(MAKE) all

.PHONY : all clean fclean re