/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:58:40 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 15:39:01 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_diagonal(int y, int x, int location[10][10])
{
	int		left_x;
	int		right_x;
	int		temp_y;

	left_x = x - 1;
	right_x = x + 1;
	temp_y = y - 1;
	while (temp_y >= 0 && right_x < 10)
	{
		if (location[temp_y][right_x])
			return (0);
		temp_y -= 1;
		right_x += 1;
	}
	temp_y = y - 1;
	while (temp_y >= 0 && left_x >= 0)
	{
		if (location[temp_y][left_x])
			return (0);
		temp_y -= 1;
		left_x -= 1;
	}
	return (1);
}

int	check_column(int y, int x, int location[10][10])
{
	int		index;

	index = 0;
	while (index < y)
	{
		if (location[index][x] == 1)
			return (0);
		index++;
	}
	return (1);
}

void	print(int location[10][10])
{
	int		y;
	int		x;
	char	result;

	y = 0;
	while (y <= 9)
	{
		x = 0;
		while (x <= 9)
		{
			if (location[y][x])
			{
				result = x + 48;
				write(1, &result, 1);
				break ;
			}
			x++;
		}
		y++;
	}
	write(1, "\n", 1);
}

int	solve(int y, int location[10][10])
{
	int		x;
	int		result;

	x = 0;
	result = 0;
	if (y == 10)
	{
		print(location);
		return (1);
	}
	while (x <= 9)
	{
		if (check_column(y, x, location) && check_diagonal(y, x, location))
		{
			location[y][x] = 1;
			result += solve(y + 1, location);
			location[y][x] = 0;
		}
		x++;
	}	
	return (result);
}

int	ft_ten_queens_puzzle(void)
{
	int		location[10][10];
	int		y;
	int		x;

	y = 0;
	while (y <= 9)
	{
		x = 0;
		while (x <= 9)
		{
			location[y][x] = 0;
			x++;
		}
		y++;
	}
	return (solve(0, location));
}
