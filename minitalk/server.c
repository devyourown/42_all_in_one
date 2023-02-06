/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:17:19 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/08 16:20:32 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

char	g_sent_alpha;

int	main(void)
{
	int		count;

	print_pid();
	count = 0;
	g_sent_alpha = 0;
	while (1)
	{
		if (handle_signal() == -1)
			return (1);
		count++;
		if (count == 8)
		{
			count = 0;
			write(1, &g_sent_alpha, 1);
			g_sent_alpha = 0;
		}
		g_sent_alpha <<= 1;
	}
	return (0);
}

void	print_pid(void)
{
	char		*pid;

	pid = ft_itoa(getpid());
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

int	handle_signal(void)
{
	if (signal(SIGUSR1, handler) == SIG_ERR)
		return (-1);
	if (signal(SIGUSR2, handler) == SIG_ERR)
		return (-1);
	pause();
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_sent_alpha |= 1;
}
