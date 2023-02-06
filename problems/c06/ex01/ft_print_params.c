/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:03:12 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 11:05:29 by hyojulee         ###   ########.fr       */
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
	int		index;

	index = 1;
	while (index < argc)
	{
		write(1, argv[index], get_strlen(argv[index]));
		write(1, "\n", 1);
		index++;
	}
}
