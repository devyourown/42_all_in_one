/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:20:58 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/03 18:13:23 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

extern char	*g_filename;

void	ft_strcpy(char *str1, char *str2);

void	make_map_file(void)
{
	int		fd;
	char	buf;

	g_filename = (char *)malloc(sizeof(char) * 15);
	if (g_filename == NULL)
		exit(1);
	ft_strcpy(g_filename, "custom_map.txt");
	fd = open(g_filename, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
}
