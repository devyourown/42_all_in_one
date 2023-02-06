/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:44:22 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/23 21:44:33 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	g_directions[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int	g_board[4][4];
int	g_seen_num[16];
int	g_permu[24][4];
int	g_permu_index;

void	put_permu_to_board(int row, int permu_index);
void	permutation(int idx, int data[], int *visited);
int		check_column();
int		check_row(int row);
int		get_seen_buildings(int y, int x, int direction);
int		solve(int y);
char	get_char_from_int(int object);

char	get_char_from_int(int object)
{
	return (object + 48);
}

void	print()
{
	int		y;
	int		x;
	char	num;

	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			num = get_char_from_int(g_board[y][x]);
			write(1, &num, 1);
			if (x != 3)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int	solve(int y)
{
	int		index;
	int		result;

	index = 0;
	if (y == 4)
	{
		if (check_column())
		{
			print();
			return (1);
		}
	}
	while (index < 24)
	{
		put_permu_to_board(y, index);
		if (check_row(y))
		{
			result = solve(y+1);
			if (result)
				return (1);
		}
		index++;
	}
	return (0);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		index;
	int		seen_num_index;
	int		data[4];
	int		visited[5];

	index = 0;
	seen_num_index = 0;
	g_permu_index = 0;
	while(index < 4)
	{
		visited[index] = 0;
		data[index] = 0;
		index++;
	}
	visited[index] = 0;
	permutation(0, data, visited);
	if (argc != 2)
		return (0);
	index = 0;
	while (argv[1][index])
	{
		if (index % 2 == 1)
		{
			index++;
			continue ;
		}
		g_seen_num[seen_num_index++] = argv[1][index] - 48;
		index++;
	}
	if (!solve(0))
		write(1, "Error\n", 6);
	
}
