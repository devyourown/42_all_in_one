/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:10:56 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 11:43:19 by hyojulee         ###   ########.fr       */
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

extern t_board_size	g_size;
extern t_shape		g_shape;

int		get_board(char **board);
void	print(char **board, int **cache);
void	free_all(char **board, int **cache);

int	get_min(int right, int down, int right_down)
{
	int	result;

	result = right;
	if (result > down)
		result = down;
	if (result > right_down)
		result = right_down;
	return (result);
}

int	is_in_range(int y, int x)
{
	if (y < 0 || y >= g_size.y_size || x < 0 || x >= g_size.x_size)
		return (0);
	return (1);
}

int	solve(int y, int x, char **board, int **cache)
{
	int	right;
	int	down;
	int	right_down;
	int	result;

	if (!is_in_range(y, x))
		return (0);
	if (cache[y][x] != -1)
		return (cache[y][x]);
	if (board[y][x] == g_shape.obstacle)
	{
		cache[y][x] = 0;
		return (0);
	}
	result = 1;
	right = solve(y, x + 1, board, cache);
	down = solve(y + 1, x, board, cache);
	right_down = solve(y + 1, x + 1, board, cache);
	result += get_min(right, down, right_down);
	cache[y][x] = result;
	return (result);
}

void	draw_cache(char **board, int **cache)
{
	int		y_index;
	int		x_index;

	y_index = 0;
	if (get_board(board))
	{
		while (y_index < g_size.y_size)
		{
			x_index = 0;
			while (x_index < g_size.x_size)
			{
				solve(y_index, x_index, board, cache);
				x_index++;
			}
			y_index++;
		}
	}
	else
	{
		write(2, "map error\n", 10);
		return ;
	}
	print(board, cache);
}
