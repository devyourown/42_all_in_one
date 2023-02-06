/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:54:38 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/03 20:55:31 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup((char *)s2));
	if (s2 == NULL)
		return (ft_strdup((char *)s1));
	result = (char *)malloc(sizeof(char) * (
				ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	ft_memmove(result, s1, ft_strlen(s1));
	ft_memmove(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (result);
}

char	*ft_strdup(char *src)
{
	int		length;
	int		index;
	char	*result;

	index = 0;
	length = ft_strlen(src);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	while (src[index])
	{
		result[index] = src[index];
		index++;
	}
	result[index] = 0;
	return (result);
}

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

size_t	ft_strlen(const char *str)
{
	size_t		result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}
