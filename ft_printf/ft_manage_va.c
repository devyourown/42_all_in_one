/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_va.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:40:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/02 12:21:36 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_va(char conversion, va_list ap)
{
	char	*hex[2];

	hex[0] = "0123456789abcdef";
	hex[1] = "0123456789ABCDEF";
	if (conversion == 'd' || conversion == 'i')
		return (print_number(ap));
	else if (conversion == 'c')
		return (print_character(ap));
	else if (conversion == 's')
		return (print_str(ap));
	else if (conversion == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (print_void(ap, hex[0]));
	}
	else if (conversion == 'u')
		return (print_unumber(ap));
	else if (conversion == 'x')
		return (print_hexnumber(ap, hex[0]));
	else if (conversion == 'X')
		return (print_hexnumber(ap, hex[1]));
	else if (conversion == '%')
		return (print_percent());
	return (0);
}

int	print_hexnumber(va_list ap, char *hex)
{
	char			result[12];
	int				index;
	unsigned int	number;

	number = va_arg(ap, int);
	if (number == 0)
	{
		if (write(1, &"0", 1) == -1)
			return (-1);
		return (1);
	}
	index = 0;
	while (number != 0)
	{
		result[index++] = hex[number % 16];
		number /= 16;
	}
	result[index] = '\0';
	if (print_reverse(result, ft_strlen(result)) == -1)
		return (-1);
	return (ft_strlen(result));
}

int	print_percent(void)
{
	char	percent;

	percent = '%';
	write(1, &percent, 1);
	return (1);
}

int	print_reverse(char *str, int length)
{
	while (length > 0)
	{
		if (write(1, &str[--length], 1) == -1)
			return (-1);
	}
	return (1);
}
