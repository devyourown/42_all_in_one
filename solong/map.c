/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:54 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 14:28:37 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_map(t_map *map)
{
	if (!is_rectangle(map))
		return (0);
	if (!has_essential_element(map))
		return (0);
	if (!has_unsuitable(map))
		return (0);
	if (!wrapped_wall(map))
		return (0);
	if (has_duplicates(map))
		return (0);
	if (!has_path_to_exit(map))
		return (0);
	return (1);
}

int	is_rectangle(t_map *map)
{
	if (map->total_size != (map->x_size * map->y_size))
		return (0);
	return (1);
}

int	make_map(t_map *map, char *file_name)
{
	int		fd;
	char	map_reader;
	int		x;
	int		y;

	allocate_size(map, file_name);
	x = 0;
	y = 0;
	if (!allocate_memory(map))
		return (0);
	fd = open(file_name, O_RDONLY);
	while (read(fd, &map_reader, 1))
	{
		if (map_reader == '\n')
		{
			x = 0;
			y++;
			continue ;
		}
		map->map[y][x++] = map_reader;
	}
	close(fd);
	set_object_score(map);
	set_player_position(map);
	return (1);
}

void	allocate_size(t_map *map, char *file_name)
{
	map->x_size = get_x_size(file_name);
	map->y_size = get_y_size(file_name);
	map->total_size = get_total_size(file_name);
}

int	allocate_memory(t_map *map)
{
	int	y;

	y = 0;
	map->map = (char **)malloc(sizeof(char *) * map->y_size);
	if (map->map == NULL)
		return (0);
	while (y < map->y_size)
	{
		map->map[y] = (char *)malloc(sizeof(char) * map->x_size);
		if (map->map[y] == NULL)
			return (0);
		y++;
	}
	return (1);
}
