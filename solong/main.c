/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:05:16 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 14:29:06 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		return (1);
	check_input(argv[1]);
	map_init(argv[1], &map);
	rendering_init(&map);
	return (0);
}

void	check_input(char *input)
{
	if (!check_filename(input))
	{
		write(2, "filename Error\n", 15);
		exit(0);
	}
}

void	map_init(char *filename, t_map *map)
{
	if (!make_map(map, filename))
	{
		write(2, "Memory Error\n", 13);
		exit(0);
	}
	if (!check_map(map))
	{
		write(2, "Map Error\n", 10);
		exit(0);
	}
}
