# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 21:04:09 by hyojulee          #+#    #+#              #
#    Updated: 2022/09/13 15:25:02 by hyojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCC = cc -Wall -Wextra -Werror
INCLUDE_DIR = ./
SRCS = ft_strlen.c ft_itoa.c ft_printf.c ft_print_function.c ft_manage_va.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
	$(GCC) -I$(INCLUDE_DIR) -c -o $@ $<

$(NAME) : $(OBJS)
	ar -crs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
