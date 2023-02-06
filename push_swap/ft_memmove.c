/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:15 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 17:34:16 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	*ft_memmove(void *dest, void *source, int num)
{
	int			*dest_temp;
	int			*source_temp;

	dest_temp = dest;
	source_temp = source;
	if (dest == source)
		return (dest);
	if (dest > source)
	{
		while (num)
		{
			num--;
			dest_temp[num] = source_temp[num];
		}
	}
	else
	{
		while (num--)
			*(dest_temp++) = *(source_temp++);
	}
	return (dest);
}
