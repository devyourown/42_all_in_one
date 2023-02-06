/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:36:36 by hyojulee          #+#    #+#             */
/*   Updated: 2022/07/12 16:28:46 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	int			front_index;
	int			rear_index;

	if (s1 == NULL)
		return (NULL);
	str = NULL;
	if (set != NULL)
	{
		front_index = 0;
		rear_index = ft_strlen(s1);
		while (s1[front_index] && ft_strchr(set, s1[front_index]))
			front_index++;
		while (s1[rear_index - 1] && ft_strchr(set,
				s1[rear_index - 1]) && rear_index > front_index)
			rear_index--;
		str = (char *)malloc(sizeof(char) * (rear_index - front_index + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[front_index], rear_index - front_index + 1);
	}
	return (str);
}
