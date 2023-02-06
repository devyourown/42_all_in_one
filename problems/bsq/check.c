/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:09:14 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 11:11:39 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

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

extern t_shape		g_shape;
extern t_board_size	g_size;
extern char			*g_filename;

int	is_suitable(char c);
int	pass_first_line(int fd);
int	map_check(void);

int	pass_first_line(int fd)
{
	char	c;
	int		count;

	count = 0;
	if (g_shape.obstacle == g_shape.box)
		return (0);
	if (g_shape.obstacle == g_shape.blank)
		return (0);
	if (g_shape.blank == g_shape.box)
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		count++;
	}
	if (count < 4)
		return (0);
	return (1);
}

int	check_map_size(int fd)
{
	int		y_count;
	int		x_count;
	char	c;

	y_count = 0;
	x_count = 0;
	while (read(fd, &c, 1))
	{
		if (c != '\n' && !(is_suitable(c)))
			return (0);
		if (c == '\n')
		{
			y_count++;
			if (x_count != g_size.x_size)
				return (0);
			x_count = 0;
			continue ;
		}
		x_count++;
	}
	if (y_count != g_size.y_size)
		return (0);
	return (1);
}

int	map_check(void)
{
	int				fd;

	fd = open(g_filename, O_RDONLY);
	if (!pass_first_line(fd))
		return (0);
	if (g_size.y_size == 0)
		return (0);
	if (!check_map_size(fd))
		return (0);
	close(fd);
	return (1);
}

int	is_suitable(char c)
{
	int		result;

	result = 0;
	if (c == g_shape.obstacle)
		result = 1;
	if (c == g_shape.blank)
		result = 1;
	return (result);
}
