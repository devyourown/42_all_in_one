/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:07:28 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 12:19:49 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

char			*g_filename;
t_board_size	g_size;

void	free_all(char **board, int **cache);
int		initialize_size(void);
void	initialize_cache(int **cache);
void	draw_cache(char **board, int **cache);
void	initialize_filename(char *str);
void	make_map_file(void);

void	handle_initial_error(void)
{
	write(2, "map error\n", 10);
	free(g_filename);
}

void	free_all(char **board, int **cache)
{
	int		index;

	index = 0;
	while (index < g_size.y_size)
	{
		free(board[index]);
		free(cache[index]);
		index++;
	}
	free(board);
	free(cache);
	free(g_filename);
}

void	execute(void)
{
	char	**board;
	int		**cache;
	int		index;

	if (initialize_size())
	{
		handle_initial_error();
		return ;
	}
	board = (char **)malloc(sizeof(char *) * (g_size.y_size + 1));
	cache = (int **)malloc(sizeof(int *) * (g_size.y_size) * sizeof(int));
	if (board == NULL || cache == NULL)
		exit(1);
	index = 0;
	while (index < g_size.y_size)
	{
		board[index] = (char *) malloc(sizeof(char) * (g_size.x_size));
		cache[index] = (int *)malloc(sizeof(int) * (g_size.x_size));
		if (board[index] == NULL || cache[index] == NULL)
			exit(1);
		index++;
	}
	initialize_cache(cache);
	draw_cache(board, cache);
	free_all(board, cache);
}

int	main(int argc, char **argv)
{
	int				index;

	if (argc == 1)
	{
		make_map_file();
		execute();
		return (0);
	}
	else
	{
		index = 1;
		while (index < argc)
		{
			if (index >= 2)
				write(1, "\n", 1);
			initialize_filename(argv[index]);
			execute();
			index++;
		}
	}
	return (0);
}
