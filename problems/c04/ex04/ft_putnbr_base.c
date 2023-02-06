/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:36:49 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/27 10:55:27 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

unsigned int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	get_strlength(char *str)
{
	int		index;

	index = 0;
	while (*str)
	{
		str++;
		index++;
	}
	return (index);
}

int	check_exception(char *base)
{
	char	word[128];
	int		index;

	index = 0;
	while (index < 128)
		word[index++] = 1;
	if (get_strlength(base) <= 1)
		return (-1);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (-1);
		if (word[(int)(*base)] != 1)
			return (-1);
		else
			word[(int)(*base)]++;
		base++;
	}
	return (0);
}

void	print_rev_arr(char *str, int index)
{
	while (index >= 0)
	{
		write(1, &str[index--], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				index;
	unsigned int	absolute_value;
	char			result[33];
	int				base_length;

	index = 0;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	base_length = get_strlength(base);
	absolute_value = absolute(nbr);
	if (check_exception(base) == -1)
		return ;
	while (absolute_value)
	{
		result[index++] = base[absolute_value % base_length];
		absolute_value /= base_length;
	}
	if (nbr < 0)
		result[index++] = '-';
	print_rev_arr(result, --index);
}
