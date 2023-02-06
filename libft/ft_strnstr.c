/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:11:28 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/02 11:11:29 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
