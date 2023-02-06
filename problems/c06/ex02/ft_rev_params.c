/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:06:33 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 11:09:10 by hyojulee         ###   ########.fr       */
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
	while (argc > 1)
	{
		write(1, argv[argc - 1], get_strlen(argv[argc - 1]));
		write(1, "\n", 1);
		argc--;
	}
}
