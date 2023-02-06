/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:19 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 11:21:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_board_size
{
	int		y_size;
	int		x_size;
}	t_board_size;

typedef struct s_shape
{
	char	obstacle;
	char	box;
	char	blank;
}	t_shape;

extern char			*g_filename;
extern t_board_size	g_size;

int		get_board_x_size(void);
int		get_board_y_size(int y_length);
void	get_map_info(int *y_length);

int	get_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_strcpy(char *str1, char *str2)
{
	int		index;

	index = 0;
	while (str2[index])
	{
		str1[index] = str2[index];
		index++;
	}
	str1[index] = 0;
}

void	initialize_cache(int **cache)
{
	int		y;
	int		x;

	y = 0;
	while (y < g_size.y_size)
	{
		x = 0;
		while (x < g_size.x_size)
		{
			cache[y][x] = -1;
			x++;
		}
		y++;
	}
}

void	initialize_filename(char *str)
{
	g_filename = (char *)malloc(sizeof(char) * get_strlen(str) + 1);
	if (g_filename == NULL)
		exit(1);
	ft_strcpy(g_filename, str);
}

int	initialize_size(void)
{
	int		y_length;

	y_length = 0;
	get_map_info(&y_length);
	g_size.x_size = get_board_x_size();
	g_size.y_size = get_board_y_size(y_length);
	if (g_size.y_size == -1)
		return (1);
	else
		return (0);
}
