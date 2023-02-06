/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:34:53 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 20:29:52 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t num)
{
	char			*dest_temp;
	const char		*source_temp;

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
