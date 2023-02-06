/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:30:49 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 18:23:56 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#include "convert.h"
#include "pushswap.h"

t_boolean	validate_args(char **argv, int argc)
{
	int		index;
	int		*arr;

	index = 0;
	while (index < argc)
	{
		if (!is_integer(argv[index]))
			return (false);
		index++;
	}
	arr = convert_to_int_array(argv, argc);
	if (arr == NULL)
		return (false);
	if (has_duplicates(arr, argc))
	{
		free(arr);
		return (false);
	}
	free(arr);
	return (true);
}

t_boolean	is_integer(const char *str)
{
	int			index;
	long long	num;

	index = 0;
	while (index < ft_strlen(str))
	{
		if (!(('0' <= str[index] && str[index] <= '9') || str[index] == '-'
				|| str[index] == ' '))
			return (false);
		index++;
	}
	num = ft_atol(str);
	if (-2147483648 > num || num > 2147483647)
		return (false);
	return (true);
}

t_boolean	has_duplicates(int *arr, int length)
{
	int		first_index;
	int		second_index;

	first_index = 0;
	second_index = 1;
	while (first_index < length)
	{
		while (second_index < length)
		{
			if (arr[first_index] == arr[second_index])
				return (true);
			second_index++;
		}
		first_index++;
		second_index = first_index + 1;
	}
	return (false);
}
