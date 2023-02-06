/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:41:02 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 11:21:29 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	pass_first_line(int fd);
int	map_check(void);

typedef struct s_board_size
{
	int		y_size;
	int		x_size;
}	t_board_size;

typedef struct s_shape
{
	char	obstacle;
	char	box;
	char	blank;
}	t_shape;

extern char			*g_filename;
t_shape				g_shape;
extern t_board_size	g_size;

int	get_board_x_size(void)
{
	int		fd;
	char	c;
	int		count_x;

	count_x = 0;
	fd = open(g_filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	pass_first_line(fd);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		count_x++;
	}
	close(fd);
	return (count_x);
}

int	get_board_y_size(int y_length)
{
	int		fd;
	char	c;
	int		result;
	int		index;

	result = 0;
	index = 0;
	fd = open(g_filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) && index < y_length)
	{
		if (!('0' <= c && c <= '9'))
		{
			return (-1);
		}
		result = 10 * result + (c - 48);
		index++;
	}
	close(fd);
	return (result);
}

void	get_map_info(int *y_length)
{
	int		fd;
	char	c;
	char	shape[3];
	int		index;

	index = 0;
	fd = open(g_filename, O_RDONLY);
	if (fd == -1)
		return ;
	while (index < 3 && read(fd, &c, 1))
		shape[index++] = c;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		index = -1;
		while (index++ < 2)
			shape[index] = shape[index + 1];
		shape[2] = c;
		(*y_length)++;
	}
	g_shape.blank = shape[0];
	g_shape.obstacle = shape[1];
	g_shape.box = shape[2];
	close(fd);
}

int	get_board(char **board)
{
	int		fd;
	char	c;
	int		y;
	int		x;

	if (!map_check())
		return (0);
	fd = open(g_filename, O_RDONLY);
	pass_first_line(fd);
	y = 0;
	x = 0;
	while (read(fd, &c, 1))
	{
		if (x == g_size.x_size)
		{
			y++;
			x = 0;
			continue ;
		}
		board[y][x++] = c;
	}
	close(fd);
	return (1);
}
