/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:54:36 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/03 22:07:38 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*shared;
	int			size;
	char		reader[BUFFER_SIZE + 1];

	if (shared != NULL && has_nl(shared) != -1)
		return (split_two_str(shared, "", &shared));
	size = read(fd, reader, BUFFER_SIZE);
	if (size == -1 || size == 0)
		return (split_two_str(shared, "", &shared));
	reader[size] = '\0';
	if (has_nl(reader) != -1)
		return (split_two_str(shared, reader, &shared));
	while (size != 0)
	{
		shared = ft_strjoin(shared, reader);
		size = read(fd, reader, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		reader[size] = '\0';
		if (has_nl(reader) != -1)
			return (split_two_str(shared, reader, &shared));
	}
	return (split_two_str(shared, "", &shared));
}

char	*split_two_str(char *s1, char *s2, char **rear)
{
	char	*merged;
	char	*front;
	int		divide_point;

	merged = ft_strjoin(s1, s2);
	if (has_nl(merged) == -1)
		divide_point = ft_strlen(merged);
	else
		divide_point = has_nl(merged) + 1;
	front = ft_substr(merged, 0, divide_point);
	if (ft_strlen(merged) == (unsigned int)(divide_point))
		*rear = NULL;
	else
		*rear = ft_substr(merged, divide_point,
				ft_strlen(merged) - divide_point + 1);
	free(merged);
	return (front);
}

int	has_nl(char *str)
{
	size_t		index;

	index = 0;
	while (index < ft_strlen(str))
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			index;

	index = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
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
