/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:53:06 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 10:59:32 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
		return (0);
	write(1, argv[0], get_strlen(argv[0]));
	write(1, "\n", 1);
}
