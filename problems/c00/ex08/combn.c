/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:24:46 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 15:36:06 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int arr[10], int n)
{
	char	c;
	int		index;

	index = 0;
	while (index < n)
	{
		c = arr[index] + 48;
		write(1, &c, 1);
		index++;
	}
	if (arr[0] != 10 - n)
		write(1, ", ", 2);
}

void	combn(int arr[10], int picked, int n)
{
	int		next_num;

	if (picked == n)
	{
		print(arr, n);
		return ;
	}
	if (picked == 0)
		next_num = 0;
	else
		next_num = arr[picked - 1] + 1;
	while (next_num <= 9)
	{
		arr[picked] = next_num;
		combn(arr, picked + 1, n);
		next_num++;
	}
}

void	ft_print_combn(int n)
{
	int		arr[10];
	
	combn(arr, 0, n);
}

int	main(void)
{
	ft_print_combn(3);
}
