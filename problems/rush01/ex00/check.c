/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:29:27 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/23 21:43:56 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern  int g_seen_num[16];
extern  int g_directions[4][2];
extern  int g_board[4][4];

int		get_seen_buildings(int y, int x, int direction);

int	check_column()
{
	int		index;
	int		up_seen;
	int		down_seen;

	index = 0;
	while (index < 4)
	{
		up_seen = get_seen_buildings(0, 0 + index, 0);
		down_seen = get_seen_buildings(3, 0 + index, 3);
		if (!(g_seen_num[0 + index] == up_seen))
			return (0);
		if (!(g_seen_num[4 + index] == down_seen))
			return (0);
		index++;
	}
	return (1);
}

int	check_row(int row)
{
	int		left_seen;
	int		right_seen;
	
	left_seen = get_seen_buildings(row, 0, 1);
	right_seen = get_seen_buildings(row, 3, 2);
	if (!(g_seen_num[8+row] == left_seen))
		return (0);
	if (!(g_seen_num[12+row] == right_seen))
		return (0);
	return (1);
}

int	get_seen_buildings(int y, int x, int direction)
{
	int	index;
	int	max;
	int	count;
	int	dx;
	int	dy;

	index = 0;
	max = g_board[y][x];
	count = 1;
	while (index < 3)
	{
		dy = g_directions[direction][0];
		dx = g_directions[direction][1];
		if (max < g_board[y + dy][x + dx])
		{
			max = g_board[y + dy][x + dx];
			count++;
		}
		y += dy;
		x += dx;
		index++;
	}
	return (count);
}


