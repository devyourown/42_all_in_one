/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:18:13 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/02 12:19:45 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		format_index;
	int		bytes;
	int		result;

	format_index = 0;
	result = 0;
	va_start(ap, format);
	while (format[format_index])
	{
		if (format[format_index] == '%')
		{
			bytes = print_va(format[++format_index], ap);
			if (bytes == -1)
				return (-1);
			result += bytes;
			result -= 1;
		}
		else
			write(1, &format[format_index], 1);
		result += 1;
		format_index++;
	}
	va_end(ap);
	return (result);
}
