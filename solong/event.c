/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:59:16 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 14:13:14 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	press_key_event(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		move(map, -1, 0);
	if (keycode == KEY_A)
		move(map, 0, -1);
	if (keycode == KEY_S)
		move(map, +1, 0);
	if (keycode == KEY_D)
		move(map, 0, +1);
	render(map);
	return (0);
}

int	press_red_button(int result)
{
	exit(result);
}

void	move(t_map *map, int y, int x)
{
	char	cur_char;
	char	*movements;

	cur_char = map->map[map->position.y + y][map->position.x + x];
	if (cur_char == '1')
		return ;
	if (cur_char == 'C')
		map->score++;
	if (cur_char == 'E' && map->score == map->object_score)
		exit(0);
	if (map->map[map->position.y][map->position.x] != 'E')
		map->map[map->position.y][map->position.x] = '0';
	map->position.y += y;
	map->position.x += x;
	movements = ft_itoa(++(map->movements));
	write(1, "movements : ", 12);
	write(1, movements, ft_strlen(movements));
	write(1, "\n", 1);
	if (map->map[map->position.y][map->position.x] != 'E')
		map->map[map->position.y][map->position.x] = 'P';
}
