/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:24:47 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/25 16:43:53 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar_reverse(char *str, int index)
{
	while (index >= 0)
		write(1, &str[index--], 1);
}

unsigned int	absol(int number)
{
	if (number < 0)
		return ((unsigned int)(-number));
	return ((unsigned int)(number));
}

void	ft_putnbr(int nb)
{
	char			decimal_numbers[11];
	unsigned int	absolute_value;
	int				index;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	index = 0;
	absolute_value = absol(nb);
	while (absolute_value)
	{
		decimal_numbers[index++] = (absolute_value % 10) + 48;
		absolute_value /= 10;
	}
	if (nb < 0)
		decimal_numbers[index++] = '-';
	ft_putchar_reverse(decimal_numbers, --index);
}
