/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:37:27 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 13:46:13 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	rendering_init(t_map *map)
{
	map->mlx = mlx_init();
	map->movements = 0;
	put_img(map);
	map->window = mlx_new_window(map->mlx, 32 * map->x_size,
			32 * map->y_size, "game");
	render(map);
	mlx_hook(map->window, 2, 0, &press_key_event, map);
	mlx_hook(map->window, 17, 0, &press_red_button, 0);
	mlx_loop(map->mlx);
}

void	put_img(t_map *map)
{
	map->img_height = 32;
	map->img_width = 32;
	map->wall_img = mlx_xpm_file_to_image(map->mlx, "./images/wall.xpm",
			&map->img_width, &map->img_height);
	map->player_img = mlx_xpm_file_to_image(map->mlx, "./images/player.xpm",
			&map->img_width, &map->img_height);
	map->collect_img = mlx_xpm_file_to_image(map->mlx, "./images/collect.xpm",
			&map->img_width, &map->img_height);
	map->empty_img = mlx_xpm_file_to_image(map->mlx, "./images/empty.xpm",
			&map->img_width, &map->img_height);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm",
			&map->img_width, &map->img_height);
	map->grass_img = mlx_xpm_file_to_image(map->mlx, "./images/grass.xpm",
			&map->img_width, &map->img_height);
}

void	render(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			draw_img(map, map->empty_img, x * 32, y * 32);
			if (map->map[y][x] == '1')
				draw_img(map, map->wall_img, x * 32, y * 32);
			else if (map->map[y][x] == 'C')
				draw_img(map, map->collect_img, x * 32, y * 32);
			else if (map->map[y][x] == 'E')
				draw_img(map, map->exit_img, x * 32, y * 32);
			else if (map->map[y][x] == 'P')
				draw_img(map, map->player_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	draw_img(map, map->player_img, map->position.x * 32, map->position.y * 32);
}

void	draw_img(t_map *map, void *img, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->window, img, y, x);
}
