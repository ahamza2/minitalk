# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:28:18 by haarab            #+#    #+#              #
#    Updated: 2023/02/08 15:55:28 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk 

SERVER = server

CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJS = server.o client.o libft.o

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER) : server.c libft.c
	$(CC) $(CFLAGS) -o server server.c libft.c

$(CLIENT) : client.c libft.c
	$(CC) $(CFLAGS) -o client client.c libft.c

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) server client

re: fclean all

.PHONY : all clean fclean re