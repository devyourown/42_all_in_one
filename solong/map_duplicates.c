/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:18 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/08 17:05:09 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	has_duplicates(t_map *map)
{
	int	count_exit;
	int	count_start_position;

	count_exit = count_specific_character(map, 'E');
	count_start_position = count_specific_character(map, 'P');
	if (count_exit > 1)
		return (1);
	if (count_start_position > 1)
		return (1);
	return (0);
}

int	count_specific_character(t_map *map, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (y < map->y_size)
	{
		while (x < map->x_size)
		{
			if (map->map[y][x] == c)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}
