/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:43:08 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/03 11:02:39 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_position
{
	int	x_pos;
	int	y_pos;
}	t_position;

extern t_shape			g_shape;
extern t_board_size		g_size;

t_position	get_max_position(int **cache, int *value)
{
	int			y;
	int			x;
	int			max;
	t_position	pos;

	y = 0;
	max = 0;
	while (y < g_size.y_size)
	{
		x = 0;
		while (x < g_size.x_size)
		{
			if (max < cache[y][x])
			{
				max = cache[y][x];
				pos.x_pos = x;
				pos.y_pos = y;
			}
			x++;
		}
		y++;
	}
	*value = max;
	return (pos);
}

void	draw_box(char **board, int **cache)
{
	t_position	position;
	int			value;
	int			end_x;
	int			end_y;
	int			start_x;

	position = get_max_position(cache, &value);
	end_x = position.x_pos + value;
	end_y = position.y_pos + value;
	start_x = position.x_pos;
	while (position.y_pos < end_y)
	{
		position.x_pos = start_x;
		while (position.x_pos < end_x)
		{
			board[position.y_pos][position.x_pos] = g_shape.box;
			position.x_pos++;
		}
		position.y_pos++;
	}
}

void	print(char **board, int **cache)
{
	int			y;
	int			x;

	y = 0;
	draw_box(board, cache);
	while (y < g_size.y_size)
	{
		x = 0;
		while (x < g_size.x_size)
		{
			write(1, &board[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
