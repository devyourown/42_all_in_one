/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:18 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 14:06:48 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_out_of_range(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->y_size)
		return (1);
	if (x < 0 || x >= map->x_size)
		return (1);
	return (0);
}

int	path(t_map *map, int y, int x, int **visited)
{
	if (is_out_of_range(map, y, x))
		return (0);
	if (visited[y][x] == 1)
		return (0);
	if (map->map[y][x] == '1')
		return (0);
	if (map->map[y][x] == 'E')
		return (1);
	visited[y][x] = 1;
	if (path(map, y + 1, x, visited) || path(map, y - 1, x, visited)
		|| path(map, y, x + 1, visited) || path(map, y, x - 1, visited))
		return (1);
	return (0);
}

int	**init_visited(t_map *map)
{
	int		**result;
	int		y;
	int		x;

	y = 0;
	x = 0;
	result = (int **)malloc(sizeof(int *) * map->y_size);
	if (result == NULL)
		return (NULL);
	while (y < map->y_size)
	{
		result[y] = (int *)malloc(sizeof(int) * map->x_size);
		if (result[y] == NULL)
			return (NULL);
		while (x < map->x_size)
		{
			result[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
	return (result);
}

int	has_path_to_exit(t_map *map)
{
	int		**visited;

	visited = init_visited(map);
	if (visited == NULL)
		return (1);
	if (path(map, map->position.y, map->position.x, visited))
		return (1);
	return (0);
}
