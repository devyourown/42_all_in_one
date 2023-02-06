/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:38:10 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:24:05 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static int	get_words(char const *str, char c)
{
	int			result;
	int			idx;

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

static int	get_size(char const *str, char delimeter)
{
	int		result;

	result = 0;
	while (str[result] && str[result] != delimeter)
		result++;
	return (result);
}

static int	pass_delimeter(char const *str, char c)
{
	int		index;

	index = 0;
	while (str[index] == c)
		index++;
	return (index);
}

char	*ft_substr(char const *s, int start, int len)
{
	char			*substr;
	int				index;

	index = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (index < len)
		substr[index++] = s[start++];
	substr[index] = 0;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	int				s_index;
	int				index;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (get_words(s, c) + 1));
	index = 0;
	s_index = 0;
	while (index < get_words(s, c))
	{
		while (s[s_index] == c)
			s_index++;
		result[index] = ft_substr(s, s_index, get_size(&s[s_index], c));
		index++;
		s_index += get_size(&s[s_index], c);
		s_index += pass_delimeter(&s[s_index], c);
	}
	result[index] = NULL;
	return (result);
}
