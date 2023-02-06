# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 14:45:00 by hyojulee          #+#    #+#              #
#    Updated: 2022/11/10 18:18:08 by hyojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
GCC = cc -Wall -Wextra -Werror

SRCS = main.c map_element_validator.c map.c filename.c map_size.c mlx_setting.c \
		map_initial.c event.c map_duplicates.c valid_path.c ft_itoa.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : (SRCS)
	$(GCC) -Imlx -c $^

$(NAME) : $(OBJS)
	cc -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
