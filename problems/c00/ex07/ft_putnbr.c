/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:27:41 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 14:45:44 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char arr[10], int n)
{
	while (n >= 0)
	{
		write(1, &arr[n], 1);
		n--;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	ret;
	char			result [11];
	int				i;

	ret = nb;
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
		ret = -nb;
	while (ret)
	{		
		result[i] = (ret % 10) + 48;
		ret /= 10;
		i++;
	}
	if (nb < 0)
	{
		result[i] = '-';
		i++;
	}
	print(result, i);
}
