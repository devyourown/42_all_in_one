/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_detail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:31:09 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/28 21:32:24 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	set_player_position(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			if (map->map[y][x] == 'P')
			{
				map->position.y = y;
				map->position.x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_object_score(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->object_score = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			if (map->map[y][x] == 'C')
			{
				map->object_score++;
			}
			x++;
		}
		y++;
	}
}
