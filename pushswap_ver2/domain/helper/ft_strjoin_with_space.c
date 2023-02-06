/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:13:44 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:23:50 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

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
