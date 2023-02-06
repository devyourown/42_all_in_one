/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:43:35 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 20:23:57 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_reverse(char *str, int index, int fd)
{
	while (index >= 0)
		write(fd, &str[index--], 1);
}

static unsigned int	absol(int number)
{
	if (number < 0)
		return ((unsigned int)(-number));
	return ((unsigned int)(number));
}

void	ft_putnbr_fd(int n, int fd)
{
	char			decimal_numbers[11];
	unsigned int	absolute_value;
	int				index;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	index = 0;
	absolute_value = absol(n);
	while (absolute_value)
	{
		decimal_numbers[index++] = (absolute_value % 10) + 48;
		absolute_value /= 10;
	}
	if (n < 0)
		decimal_numbers[index++] = '-';
	ft_putchar_reverse(decimal_numbers, --index, fd);
}
