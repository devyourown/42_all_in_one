/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:28:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 11:16:13 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}

int	get_length_of_words(char **strs, int size)
{
	int		length;
	int		index;

	index = 0;
	length = 0;
	while (index < size)
	{
		length += get_strlen(strs[index]);
		index++;
	}
	return (length);
}

void	ft_join(int size, char **strs, char *result, char *sep)
{
	int		index;
	int		result_index;
	int		sep_size;

	index = 0;
	result_index = 0;
	sep_size = get_strlen(sep);
	while (index < size)
	{
		if (index == size - 1)
		{
			ft_strcpy(&result[result_index], strs[index]);
			result_index += get_strlen(strs[index]);
			break ;
		}
		ft_strcpy(&result[result_index], strs[index]);
		result_index += get_strlen(strs[index]);
		ft_strcpy(&result[result_index], sep);
		result_index += sep_size;
		index++;
	}
	result[result_index] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		sep_size;
	int		words_size;

	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	sep_size = get_strlen(sep);
	words_size = get_length_of_words(strs, size);
	result = (char *)malloc(sizeof(char) * \
			(words_size + 1 + (sep_size * (size - 1))));
	if (result == NULL)
		return (NULL);
	ft_join(size, strs, result, sep);
	return (result);
}
