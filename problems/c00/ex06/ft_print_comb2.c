/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:23:55 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/14 17:26:30 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int first, int second)
{
	char	front[2];
	char	back[2];

	front[0] = first / 10 + 48;
	front[1] = first % 10 + 48;
	back[0] = second / 10 + 48;
	back[1] = second % 10 + 48;
	write(1, front, 2);
	write(1, " ", 1);
	write(1, back, 2);
	if (front[0] != '9' && front[1] != '8')
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print(first, second);
			second++;
		}
		first++;
	}
}
