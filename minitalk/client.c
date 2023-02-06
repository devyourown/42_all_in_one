/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:36:13 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/08 16:10:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	str_index;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	str_index = 0;
	while (str_index < ft_strlen(argv[2]))
	{
		if (send(pid, argv[2][str_index++]) == -1)
			return (1);
	}
	return (0);
}

int	send(int pid, char package)
{
	int	bit;
	int	count;

	count = 0;
	while (count != 8)
	{
		bit = package & 128;
		package <<= 1;
		if (bit == 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		usleep(100);
		count++;
	}
	return (0);
}
