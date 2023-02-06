/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:38:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 16:41:53 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_one_of_charset(char c, char *charset);

int	get_num_of_words(char *str, char *charset)
{
	int		index;
	int		num_of_words;
	int		is_seperator;

	index = 0;
	num_of_words = 0;
	is_seperator = 1;
	if (charset[0] == '\0')
		return (1);
	while (str[index])
	{
		if (!is_one_of_charset(str[index], charset) && is_seperator)
		{
			is_seperator = 0;
			num_of_words++;
		}
		if (is_one_of_charset(str[index], charset))
			is_seperator = 1;
		index++;
	}
	return (num_of_words);
}

int	is_one_of_charset(char c, char *charset)
{
	int		index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int	get_size_of_word(char *str, char *charset)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (is_one_of_charset(str[index], charset))
			break ;
		index++;
	}
	return (index);
}

char	*get_word(char *str, char *charset)
{
	char	*result;
	int		index;
	int		size;

	index = 0;
	size = get_size_of_word(str, charset);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (index < size)
	{
		result[index] = str[index];
		index++;
	}
	result[index] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		index;
	int		num_of_words;
	int		str_index;

	index = 0;
	str_index = 0;
	num_of_words = get_num_of_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (num_of_words + 1));
	if (!result)
		return (NULL);
	while (index < num_of_words)
	{
		while (is_one_of_charset(str[str_index], charset))
			str_index++;
		result[index] = get_word(&str[str_index], charset);
		str_index += get_size_of_word(&str[str_index], charset);
		index++;
	}
	result[index] = 0;
	return (result);
}
