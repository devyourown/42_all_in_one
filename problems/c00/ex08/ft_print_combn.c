/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:34:23 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 14:45:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve(char *result, int picked, int n)
{
	int		end;
	int		start;

	if (picked == n)
	{
		write(1, result, n);
		if (result[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	start = result[picked - 1] - '0' +1;
	end = 10 - n + picked;
	while (start <= end)
	{
		result[picked] = start + '0';
		solve(result, picked + 1, n);
		start++;
	}
}

void	ft_print_combn(int n)
{
	int		end;
	int		i;
	char	result[11];

	end = 10 - n;
	i = 0;
	while (i <= end)
	{
		result[0] = '0' + i;
		solve(result, 1, n);
		i++;
	}
}
