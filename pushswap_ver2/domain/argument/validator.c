/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:22:34 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:31:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../helper/constants.h"
#include "../helper/helper.h"
#include "argument.h"

t_boolean	validate_args(int argc, char **argv)
{
	if (!are_integers(argc, argv))
		return (false);
	if (has_duplicates(argc, argv))
		return (false);
	return (true);
}

t_boolean	are_integers(int argc, char **argv)
{
	int		index;

	index = 0;
	while (index < argc)
	{
		if (!is_integer(argv[index]))
			return (false);
		index++;
	}
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

t_boolean	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 1;
	arr = make_int_array(argc, argv);
	if (arr == NULL)
		return (false);
	while (i < argc)
	{
		while (j < argc)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (false);
}

int	*make_int_array(int argc, char **argv)
{
	int		index;
	int		*result;

	index = 0;
	result = (int *)malloc(sizeof(int) * argc);
	if (result == NULL)
		return (NULL);
	while (index < argc)
	{
		result[index] = ft_atoi(argv[index]);
		index++;
	}
	return (result);
}
