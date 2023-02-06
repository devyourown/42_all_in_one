/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:03:01 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 19:09:51 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*convert_to_int_array(char **argv, int size)
{
	int		index;
	int		*result;

	index = 0;
	result = (int *)malloc(sizeof(int) * size);
	if (result == NULL)
		return (NULL);
	while (index < size)
	{
		result[index] = ft_atoi(argv[index]);
		index++;
	}
	return (result);
}

int	count_number(char **str)
{
	int		result;

	result = 0;
	while (str[result])
	{
		result++;
	}
	return (result);
}

char	**init_input(int argc, char **argv)
{
	char	*joined;
	int		index;

	index = 1;
	joined = argv[1];
	while (index <= argc - 1)
	{
		joined = ft_strjoin_with_space(joined, argv[index + 1]);
		index++;
	}
	return (ft_split(joined, ' '));
}

char	*ft_strjoin_with_space(char *s1, char *s2)
{
	char		*result;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup((char *)s2));
	if (s2 == NULL)
		return (ft_strdup((char *)s1));
	result = (char *)malloc(sizeof(char) * (
				ft_strlen(s1) + ft_strlen(s2) + 2));
	if (result == NULL)
		return (NULL);
	ft_memmove(result, s1, ft_strlen(s1));
	result[ft_strlen(s1)] = ' ';
	ft_memmove(result + ft_strlen(s1) + 1, s2, ft_strlen(s2) + 1);
	return (result);
}

char	*ft_strdup(char *src)
{
	int		length;
	int		index;
	char	*dest;

	index = 0;
	length = ft_strlen(src);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}
