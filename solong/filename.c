/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:51:25 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 18:26:15 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_filename(char *filename)
{
	int		fd;
	char	*after_ber;

	after_ber = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (after_ber == NULL)
		return (0);
	if (ft_strlen(after_ber) != 4)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;
	size_t		needle_index;

	index = 0;
	if (!(*needle))
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (index < len)
	{
		if (haystack[index] == needle[0])
		{
			needle_index = 1;
			while ('\0' != needle[needle_index] && index + needle_index < len)
			{
				if (haystack[index + needle_index] != needle[needle_index])
					break ;
				needle_index++;
			}
			if (0 == needle[needle_index])
				return ((char *)&haystack[index]);
		}
		index++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
