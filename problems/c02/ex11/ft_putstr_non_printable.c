/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:41:32 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/21 18:02:17 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_non_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (0);
	return (1);
}

void	print_hex(unsigned char c)
{
	write(1, "\\", 1);
	write(1, &"0123456789abcdef"[c / 16], 1);
	write(1, &"0123456789abcdef"[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	non_printable_word;

	index = 0;
	while (str[index])
	{
		non_printable_word = str[index];
		if (is_non_printable(non_printable_word))
		{
			print_hex(non_printable_word);
		}
		else
			write(1, &str[index], 1);
		index++;
	}
}
