/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:20:16 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 13:42:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	has_unsuitable(t_map *map)
{
	int	y;
	int	x;
	int	result;

	result = 1;
	y = 0;
	x = 0;
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			if (!is_suitable(map->map[y][x]))
				result = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (result);
}

int	is_suitable(char character)
{
	if (character == 'C' || character == '0' || character == '1')
		return (1);
	if (character == 'E' || character == 'P')
		return (1);
	return (0);
}

int	has_essential_element(t_map *map)
{
	int	has_exit;
	int	has_collect;
	int	has_start;

	has_exit = has_specific_character(map, 'E');
	has_collect = has_specific_character(map, 'C');
	has_start = has_specific_character(map, 'P');
	return (has_collect && has_exit && has_start);
}

int	has_specific_character(t_map *map, char c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			if (map->map[y][x] == c)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	wrapped_wall(t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			if (y == 0 || y == map->y_size - 1 \
					|| x == 0 || x == map->x_size - 1)
				if (map->map[y][x] != '1')
					return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
