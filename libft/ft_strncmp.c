/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:33:37 by hyojulee          #+#    #+#             */
/*   Updated: 2022/07/12 18:07:16 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		index;
	unsigned char		*compare1;
	unsigned char		*compare2;

	compare1 = (unsigned char *)s1;
	compare2 = (unsigned char *)s2;
	index = 0;
	while (n--)
	{
		if (compare1[index] != compare2[index] || compare1
			[index] == 0 || compare2[index] == 0)
			return (compare1[index] - compare2[index]);
		index++;
	}
	return (0);
}
