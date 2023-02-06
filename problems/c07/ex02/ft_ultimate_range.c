/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:43:04 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 11:07:29 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	index;
	long	size;
	int		*arr;

	size = max - min;
	index = 0;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (-1);
	while (index < size)
	{
		arr[index] = min++;
		index++;
	}
	*range = arr;
	return ((int)size);
}
