# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajafy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 08:42:28 by ajafy             #+#    #+#              #
#    Updated: 2022/05/13 08:42:30 by ajafy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCC = client.c

SRCCB = client_bonus.c

SRCS = server.c

SRCSB = server_bonus.c

CC = gcc

CLIENT = client

CLIENTB = client_bonus

SERVER = server

SERVERB = server_bonus

PRINTF = printf/libftprintf.a

DIR_PRINTF = printf/

CFLAGS = -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT) $(SERVERB) $(CLIENTB)


$(SERVER): $(PRINTF) $(SRCS)
	$(CC) $(CFLAG) $(SRCS) $(PRINTF) -o $(SERVER) 

$(CLIENT): $(PRINTF) $(SRCC)
	 $(CC) $(CFLAG) $(SRCC) $(PRINTF) -o $(CLIENT)

$(SERVERB): $(PRINTF) $(SRCSB)
	 $(CC) $(CFLAG) $(SRCSB) $(PRINTF) -o $(SERVERB) 

$(CLIENTB): $(PRINTF) $(SRCCB)
	 $(CC) $(CFLAG) $(SRCCB) $(PRINTF) -o $(CLIENTB)
 
$(PRINTF):
	$(MAKE) -C $(DIR_PRINTF)

clean :
	rm -f $(CLIENT) $(SERVER) $(SERVERB) $(CLIENTB)

fclean : clean
	$(MAKE) fclean -C $(DIR_PRINTF)

re : fclean all
