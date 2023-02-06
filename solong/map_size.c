/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:04:09 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/28 16:17:53 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_x_size(char *filename)
{
	int		fd;
	char	c;
	int		result;

	fd = open(filename, O_RDONLY);
	result = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		result++;
	}
	close(fd);
	return (result);
}

int	get_y_size(char *filename)
{
	int		fd;
	char	c;
	int		result;

	fd = open(filename, O_RDONLY);
	result = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			result++;
	}
	close(fd);
	return (result);
}

int	get_total_size(char *filename)
{
	int		fd;
	char	c;
	int		result;

	fd = open(filename, O_RDONLY);
	result = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			continue ;
		result++;
	}
	close(fd);
	return (result);
}
