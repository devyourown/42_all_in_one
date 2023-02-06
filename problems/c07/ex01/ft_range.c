/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:22:52 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 11:02:21 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*result;
	int		index;
	int		start_num;

	if (min >= max)
		return (NULL);
	index = 0;
	start_num = min;
	result = malloc(sizeof(int) * (max - min));
	if (result == NULL)
		return (NULL);
	while (index < max - min)
	{
		result[index] = start_num++;
		index++;
	}
	return (result);
}
