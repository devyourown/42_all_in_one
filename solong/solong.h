/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:09:38 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 18:30:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

typedef struct s_position
{
	int	y;
	int	x;
}	t_position;

typedef struct s_map
{
	int			y_size;
	int			x_size;
	int			total_size;
	char		**map;
	void		*player_img;
	void		*collect_img;
	void		*wall_img;
	void		*empty_img;
	void		*exit_img;
	void		*grass_img;
	int			img_width;
	int			img_height;
	void		*mlx;
	void		*window;
	t_position	position;
	int			score;
	int			object_score;
	int			movements;
}	t_map;

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

int		check_map(t_map *map);
int		has_unsuitable(t_map *map);
int		has_essential_element(t_map *map);
int		wrapped_wall(t_map *map);
void	set_player_position(t_map *map);
void	set_object_score(t_map *map);
int		has_duplicates(t_map *map);
int		has_path_to_exit(t_map *map);
int		count_specific_character(t_map *map, char c);
int		is_rectangle(t_map *map);
int		make_map(t_map *map, char *file_name);
int		is_suitable(char character);
int		has_specific_character(t_map *map, char c);

int		get_x_size(char *file_name);
int		get_y_size(char *file_name);
int		get_total_size(char *file_name);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		check_filename(char *filename);

size_t	ft_strlen(const char *str);
void	allocate_size(t_map *map, char *file_name);
int		allocate_memory(t_map *map);

void	rendering_init(t_map *map);
void	put_img(t_map *map);
void	draw_img(t_map *map, void *img, int y, int x);
void	render(t_map *map);
void	render_background(t_map *map);

void	move(t_map *map, int y, int x);
int		press_key_event(int keycode, t_map *map);
int		press_red_button(int result);

void	check_input(char *input);
void	map_init(char *filename, t_map *map);

char	*ft_itoa(int n);

#endif
