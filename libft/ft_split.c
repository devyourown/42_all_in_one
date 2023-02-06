/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:10 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 21:13:23 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *str, char c)
{
	size_t			result;
	int				idx;

	result = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] != c && (str[idx + 1] == '\0' || str[idx + 1] == c))
			result++;
		idx++;
	}
	return (result);
}

static size_t	get_size(char const *str, char delimeter)
{
	size_t		result;

	result = 0;
	while (str[result] && str[result] != delimeter)
		result++;
	return (result);
}

static char	**free_all(char **target, int index)
{
	while (index >= 0)
	{
		free(target[index--]);
	}
	free(target);
	return (NULL);
}

static unsigned int	pass_delimeter(char const *str, char c)
{
	int		index;

	index = 0;
	while (str[index] == c)
		index++;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	size_t			s_index;
	size_t			index;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (get_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	s_index = 0;
	while (index < get_words(s, c))
	{
		while (s[s_index] == c)
			s_index++;
		result[index] = ft_substr(s, s_index, get_size(&s[s_index], c));
		if (result[index++] == NULL)
			return (free_all(result, index - 1));
		s_index += get_size(&s[s_index], c);
		s_index += pass_delimeter(&s[s_index], c);
	}
	result[index] = NULL;
	return (result);
}
