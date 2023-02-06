/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:35:20 by hyojulee          #+#    #+#             */
/*   Updated: 2022/07/12 18:17:02 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int		dest_index;
	unsigned int		src_index;
	unsigned int		total_size;

	dest_index = 0;
	src_index = 0;
	if (size < ft_strlen(dest) + 1)
		return (size + ft_strlen(src));
	total_size = ft_strlen(dest) + ft_strlen(src);
	while (dest[dest_index])
		dest_index++;
	while (src[src_index] && src_index + dest_index + 1 < size)
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = '\0';
	return (total_size);
}
