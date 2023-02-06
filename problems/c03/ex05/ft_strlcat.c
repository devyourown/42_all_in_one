/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:56:09 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/25 13:10:41 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dest_index;
	unsigned int		src_index;
	unsigned int		dest_length;
	unsigned int		src_length;

	dest_index = 0;
	src_index = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length >= size)
		return (src_length + size);
	while (dest[dest_index])
		dest_index++;
	while (src[src_index] && dest_index + src_index + 1 < size)
	{
		dest[dest_index + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_index + src_index] = '\0';
	return (dest_length + src_length);
}
