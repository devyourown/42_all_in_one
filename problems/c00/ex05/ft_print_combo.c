/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:10:59 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/16 17:45:54 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_combo(char arr[3], int picked)
{
	char	i;
	char	end;

	i = arr[picked - 1] + 1;
	if (picked == 3)
	{
		write(1, arr, 3);
		if (arr[0] != '7')
			write(1, ", ", 2);
		return ;
	}
	else if (picked == 2)
		end = '9';
	else
		end = '8';
	while (i <= end)
	{
		arr[picked] = i;
		recursive_combo(arr, picked + 1);
		i++;
	}
}

void	ft_print_comb(void)
{
	char	arr[3];
	char	i;

	i = '0';
	while (i <= '7')
	{
		arr[0] = i++;
		recursive_combo(arr, 1);
	}
}
