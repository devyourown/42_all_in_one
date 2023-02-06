/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:33 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/27 14:40:39 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static size_t	get_size(int n)
{
	size_t				result;
	unsigned int		temp;

	result = 1;
	temp = n;
	if (n < 0)
	{
		result += 1;
		temp = -n;
	}
	while (temp >= 10)
	{
		temp /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*result;
	unsigned int	temp;

	size = get_size(n);
	temp = n;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		temp = -n;
	result[size] = '\0';
	while (size != 0)
	{
		result[--size] = (temp % 10) + 48;
		temp /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
