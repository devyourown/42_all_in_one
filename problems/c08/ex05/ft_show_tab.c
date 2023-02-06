/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:14:04 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 16:26:46 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	get_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int		index;

	index = 0;
	while (par[index].str)
	{
		write(1, par[index].str, par[index].size);
		write(1, "\n", 1);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		write(1, par[index].copy, get_strlen(par[index].copy));
		write(1, "\n", 1);
		index++;
	}
}
