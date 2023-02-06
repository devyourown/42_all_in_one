# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:59:58 by hyojulee          #+#    #+#              #
#    Updated: 2022/11/23 14:04:34 by hyojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
GCC = cc -Wall -Wextra -Werror
SRCS = main.c validator.c operations.c ft_strlen.c ft_atoi.c ft_atol.c \
		convert.c manual_sort.c operations_impl*.c sort.c stack.c \
		sort_detail.c compare.c compare2.c sort_utils.c ft_split.c \
		ft_memmove.c manual_sort2.c sort_detail2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
	$(GCC) -c $^

$(NAME) : $(OBJS)
	$(GCC) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
