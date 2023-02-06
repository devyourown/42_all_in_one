# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 18:40:36 by hyojulee          #+#    #+#              #
#    Updated: 2022/09/27 19:39:14 by hyojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
GCC = cc -Wall -Wextra -Werror

CLIENT_SRCS = client.c ft_atoi.c ft_strlen.c
SERVER_SRCS = server.c ft_itoa.c ft_strlen.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all : $(CLIENT_NAME) $(SERVER_NAME)

.c.o : $(CLIENT_SRCS) $(SERVER_SRCS)
	$(GCC) -c $^

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(GCC) -o $@ $^

$(SERVER_NAME) : $(SERVER_OBJS)
	$(GCC) -o $@ $^

clean :
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re : fclean
	make all

.PHONY : all clean fclean re
