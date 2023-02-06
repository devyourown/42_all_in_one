/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:34:30 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 20:31:59 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	char		*dest_temp;
	const char	*source_temp;

	dest_temp = dest;
	source_temp = source;
	if (dest == source)
		return (0);
	while (num--)
		*dest_temp++ = *source_temp++;
	return (dest);
}
