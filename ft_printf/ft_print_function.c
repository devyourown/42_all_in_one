/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:09:56 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/13 14:02:27 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(va_list ap)
{
	int		arg;
	char	*result;
	int		bytes;

	arg = va_arg(ap, int);
	result = ft_itoa(arg);
	bytes = ft_strlen(result);
	if (write(1, result, bytes) == -1)
	{
		free(result);
		return (-1);
	}
	free(result);
	return (bytes);
}

int	print_str(va_list ap)
{
	char	*result;

	result = va_arg(ap, char *);
	if (result == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(1, result, ft_strlen(result)) == -1)
	{
		return (-1);
	}
	return (ft_strlen(result));
}

int	print_character(va_list ap)
{
	char	result;

	result = va_arg(ap, int);
	if (write(1, &result, 1) == -1)
		return (-1);
	return (1);
}

int	print_void(va_list ap, char *hex)
{
	char			result[20];
	int				index;
	unsigned long	number;

	number = va_arg(ap, unsigned long);
	if (number == 0)
	{
		if (write(1, &"0", 1) == -1)
			return (-1);
		return (3);
	}
	index = 0;
	while (number != 0)
	{
		result[index] = hex[number % 16];
		number /= 16;
		index++;
	}
	result[index] = '\0';
	if (print_reverse(result, ft_strlen(result)) == -1)
		return (-1);
	return (ft_strlen(result) + 2);
}

int	print_unumber(va_list ap)
{
	unsigned int	arg;
	char			*result;
	int				bytes;

	arg = va_arg(ap, unsigned int);
	result = ft_uitoa(arg);
	bytes = ft_strlen(result);
	if (write(1, result, bytes) == -1)
	{
		free(result);
		return (-1);
	}
	free(result);
	return (bytes);
}
